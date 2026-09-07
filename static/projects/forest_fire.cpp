#include "polyscope/point_cloud.h"
#include "eigen3/Eigen/Dense"
#include "polyscope/view.h"

#include <cstdlib>
#include <random>

using vec = Eigen::Vector3d;
using vec2 = Eigen::Vector2d;
using mat = Eigen::Matrix3d;
using mat2 = Eigen::Matrix2d;
using Mat = Eigen::MatrixXd;
using Vec = Eigen::VectorXi;
using vecs = std::vector<vec2>;
int N = 4000;

void print(std::string s) {
    std::cout << "[ " << s << " ]" << std::endl;
}

namespace forest{
vecs P;
Vec matter(N),fire = Vec::Zero(N);
Mat spread_kernel = Mat::Zero(N,N);
float average_radius = 0.7;
float distance_unit = 4;
float radius_sigma = 0.1;
float death_prob = 0.3;
float consume_prob = 0.6;
float grow_prob = 0.1;
float scale = 100;
float spread_prob = 0.1;
float fire_to_matter_ratio = 0.1;
float radius_to_matter_ratio = 500;
std::vector<std::vector<int>> neighboors(N);
polyscope::PointCloud* pcf;
};

vec2 randomPos() {  return vec2::Random()*forest::scale;  }
Mat kernel;

float distToForest(const vec2& x) {
    double dist = (x-forest::P[0]).norm() - forest::matter(0)/forest::radius_to_matter_ratio;
    for (int i = 1;i<N;i++)
        dist = std::min(dist,(x-forest::P[i]).norm() - forest::matter(i)/forest::radius_to_matter_ratio);
    return dist;
}

bool outside(const vec2& p){
    return p.norm()/forest::scale < 0.5;
}

vec2 poissonPointProcess(float rad) {
    using namespace forest;
    if (P.empty())
        return randomPos();
    vec2 guess = randomPos();
    while (distToForest(guess) < rad || outside(guess)){
        guess = randomPos();
    }
    return guess;
}

void computeDistanceKernel() {
    using namespace forest;
    neighboors.clear();
    neighboors.resize(N);
    spread_kernel.setZero(N,N);
    for (int i = 0;i<N;i++)
        for (int j = i;j<N;j++){
            auto d = (P[i]-P[j]).norm()/distance_unit;
            spread_kernel(i,j) = std::exp(-0.5*d*d)/distance_unit/(2*M_PI);
            spread_kernel(j,i) = spread_kernel(i,j);
            if (spread_kernel(i,j) > 1e-6){
                forest::neighboors[i].push_back(j);
                forest::neighboors[j].push_back(i);
            }
        }
}

void generateForest() {
    using namespace forest;
    P.clear();
    fire.setZero(N);
    matter.setZero(N);
    static std::mt19937 generator;
    static std::normal_distribution<double> distribution(average_radius,radius_sigma);
    for (int i = 0;i<N;i++){
        auto r = distribution(generator);
        P.push_back(poissonPointProcess(r));
        matter(i) = r*radius_to_matter_ratio;
    }
    computeDistanceKernel();
    for (int i = 0;i<1;i++){
        auto id = rand()%N;
        fire(id) = std::pow(matter(id),2./3.);
        for (auto j : forest::neighboors[id])
            fire(j) = std::pow(matter(j),2./3.);
    }
}

void simulate() {
    using namespace forest;

    static std::mt19937 gen;

    // for each tree i
    for (int i = 0;i<N;i++){
        //number of fire particules dying
        std::binomial_distribution<> death(fire(i),forest::death_prob);
        fire(i) -= death(gen);

        //number of matter particules being eaten by fire
        std::binomial_distribution<> consume(fire(i),forest::consume_prob);
        matter(i) -= consume(gen);
        // fire on a tree grows at the perimeter of the surface it occupies
        fire(i) += int(sqrt(fire(i)));

        //fire can only spread at the surface of the burning volume of the tree
        fire(i) = std::min(fire(i),int(std::pow(matter(i),2./3.)));
    }
    fire = fire.array().max(0);
    matter = matter.array().max(0);

    auto old_fire = fire;
    for (int i = 0;i<N;i++){
        //fire spreading to neighboors
        for (auto j : forest::neighboors[i]){
            // how many fire particules flies
            std::binomial_distribution<> spread(old_fire(j),spread_prob);
            auto nb_spread = spread(gen);
            // how many reach tree j
            std::binomial_distribution<> spread_nb(nb_spread,spread_kernel(i,j));
            fire(i) += spread_nb(gen);
        }
        fire(i) = std::min(fire(i),int(std::pow(matter(i),2./3.)));
    }
    fire = fire.array().max(0);
    matter = matter.array().max(0);

    pcf->addScalarQuantity("matter", matter.cast<float>()/forest::radius_to_matter_ratio);
    pcf->addScalarQuantity("fire", fire);//->setMapRange({0.,1.});
    pcf->setPointRadiusQuantity("matter",false);
}



void init () {
    generateForest();
    print("gen forest");
    forest::pcf = polyscope::registerPointCloud2D("forest ",forest::P);
    forest::pcf->addScalarQuantity("matter", forest::matter.cast<float>()/forest::radius_to_matter_ratio);
    forest::pcf->addScalarQuantity("fire", forest::fire)->setEnabled(true);
    forest::pcf->setPointRadiusQuantity("matter",false);
    forest::pcf->addScalarQuantity("kernel", forest::spread_kernel.col(0));
}

bool sim = false;

void myCallBack() {
    ImGui::Checkbox("simulate", &sim);
    if (sim || ImGui::Button("step")){
        simulate();
    }
    if (ImGui::Button("reset")){
        init();
    }
    ImGui::SliderFloat("death prob", &forest::death_prob, 0, 1);
    ImGui::SliderFloat("consume prob", &forest::consume_prob, 0, 1);
    ImGui::SliderFloat("fire to matter", &forest::fire_to_matter_ratio, 0, 1);
    if (ImGui::SliderFloat("distance_unit", &forest::distance_unit, 0, 1)){
        computeDistanceKernel();
        forest::pcf->addScalarQuantity("kernel", forest::spread_kernel.col(0));
    }
}

int main() {
    srand(time(NULL));
    polyscope::init();
    init();
    polyscope::view::style = polyscope::view::NavigateStyle::Planar;



    polyscope::state::userCallback = myCallBack;
    polyscope::show();
    return 0;
}
