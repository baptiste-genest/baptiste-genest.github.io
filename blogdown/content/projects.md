---
title: "Projects"

---

<div style="text-align:center">

Here is a selection of my favorite and most polished projects/experiments over the last 5 years, sorted by period of interest (Most recent first).
</div>

   <video 
        src="../projects/LBM_small.mp4" 
        controls 
        autoplay 
        muted 
        loop 
        style="display: block; float: right; margin-left: auto;margin-bottom: auto; margin-right: auto; width: 350px; height: auto;">
    </video>
## Lattice Boltzman Method (LBM)

Canonical solver of the LBM in D2Q9.

- Two Relaxation Time (TRT) method for the collision operator.
- Dirichlet boundary conditions: $$ f_i(x,t) = f_i^{eq}(\rho,\vec{0}) \text{,  } x\in \partial \Omega. $$

Curl visualized in blue/red.
Amazing resources: [book](https://link.springer.com/book/10.1007/978-3-319-44649-3) [blog](https://nickmcd.me/2022/10/01/procedural-wind-and-clouds-using-gpu-accelerated-lattice-boltzmann-method/).



   <video 
        src="../projects/MCDLA.mp4" 
        controls 
        autoplay 
        muted 
        loop 
        style="display: block; float: left; margin-bottom: 10px; margin-right: 30px; width: 500px; height: auto;">
    </video>
## Markov-Chain Diffusion-Limited-Aggregation (MCDLA)

A Markov Chain interpretation of the DLA process.
The idea is to replace the individual brownian motion simulation with the computation of the probability:
$$
x\in \partial X_n, f_n(x) = \mathbb{P}\left(B_{\tau_n} = x | \tau_n < \infty \right)
$$
where tau is the stopping time of a Brownian motion, coming from infinity, touching X_n, the DLA at stage n. Such computation is performed on a discrete grid as the fixpoint of the markov chain transition matrix with uniform diffusion except around the boundary of the DLA where the particles are stuck. The next stage of the DLA is computed as:

$$
X_{n+1} = X_n \cup \bigcup_{i = 1}^{\lfloor\sqrt{n}\rfloor} Y_i, \text{ where } Y_i \sim f_n
$$



<img src="forest_fire.gif" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="350" height="">
## Forest Fire simulation by coupled discrete stochastic processes

- Simple discrete model
- Geometric laws of growth.
- Some interesting properties, for instance fire can disappear completely from a tree and come back later due to spreading. 
- very tunable and upgradable
<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='./forest_fire.cpp'">Code</button>
</div>
<br>
<br>

<img src="road_gen.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="300" height="">
## Road Generation
- A* algorithm for the main track, with weights on the vertices and on the edges to avoid
height difference
- then, to get closer to a clothoïd, since they have affine curvature, I minimize the second derivative of the curvature by minimizing:
$$
\mathcal{E}(\gamma) = \int_0^1 ||\gamma^{(4)}(t)||^2 dt
$$
with an implicit scheme, where the curve is re-parametrized by arc-length at each iteration to have : `$$||\ddot{\gamma}|| = \kappa$$`.



## "Estimation of the volume of Voronoi cells in high dimension and control variables in Monte Carlo rendering"
4th year research project supervised by David Coeurjolly and Vincent Nivoliers
- Exploration of stochastic techniques in estimating the volume and barycenters of Voronoi cells in high dimension
- Improvement of Monte Carlo integration by control variate techniques, new control variate proposed
- Caracterization and proofs of domination of the new control variate over the original control variate

<div style="text-align:center">
<img src="../projects/vorayce.png" style="display:block; margin-left: auto; margin-right: auto;max-width:80%" alt="NESOTS trailer" />
<button class="button-4" style="display:center" onclick="window.location.href='../projects/rapport_pom.pdf'">Report (french)</button>
</div>


<img src="region_growing.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="250" height="">

## Image Segmentation : Region Growing and Split and Merge Algorithms

- Region Growing : use of more various metric (Wasserstein distance between histograms, Mahalanobis distance, Lp norms) to compare regions
- Efficient Split and Merge implementation using a quadtree structure and binary encoding to compute neighborhoods



<div style="text-align:center">

<button class="button-4" style="display:right" onclick="window.location.href='../projects/rapport_seg.pdf'">Report</button>
</div>

## Edge Detection : Hough Transform and improvements
- Implementation of the Active Contour Method for image segmentation
- Implementation of the Hough Transform for line detection
- New line detection algorithm based on DBScan in pixel-gradient space

<div style="text-align:center">
<img src="../projects/active_contour.png" style="display:left; margin-left: auto; margin-right: auto;max-width:40%"/>
<img src="../projects/dbscan.png" style="display:right; margin-left: auto; margin-right: auto;max-width:50%"/>
</div>

<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='../projects/rapport_edge_detection.pdf'">Report</button>
</div>

<img src="stable_fluids.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="250" height="">
## Stable Fluids implementation   
Standard [Stable Fluids](https://www.ljll.math.upmc.fr/~frey/cours/references/Stam%20J.,%20Stable%20fluids.pdf) implementation :
  - Diffusion
  - Semi-Lagrangian advection
  - Projection method with prefactored sparse laplacian matrix for poisson problem 
  `$$\Delta u = \nabla \cdot v$$`

<img src="XPBD.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="300" height="">
## Cloth simulation : Mass Spring System & XPBD 
- Implementation of Mass Spring System
- Implementation of XPBD
- Spatial Hashing for fast collision detection
<br>
<br>
<br>
<br>


## Ambiant Occlusion & Diffusion Limited Aggregation
- Quasi Monte Carlo techniques for Ambiant Occlusion on heightfields
- Improvement of DLA algorithm by simulating brownian motion in a Walk-On-Sphere way and Octree for closest point search

<div style="text-align:center">
<img src="../projects/DLA.png" style="display:left; margin-left: auto; margin-right: auto;max-width:60%"/>
<img src="../projects/AO.png" style="display:right; margin-left: auto; margin-right: auto;max-width:37%"/>
</div>

<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='../projects/rapport_computer_graphics.pdf'">Report (French)</button>
</div>

## Use of Normal information to improve differential operators on polygonal meshes  
1 month research internship supervised by David Coeurjolly.
- Various Spline based approaches to provide better estimates of non-linear edges in order improve the convergence of discretizations of differential operators based on [Fernando De Goes et al.](https://graphics.pixar.com/library/PolyDDG/paper.pdf)
 (No conclusive results)
<div style="text-align:center">
<img src="../projects/embedder.png" style="display:block; margin-left: auto; margin-right: auto;max-width:80%" alt="NESOTS trailer" />
<button class="button-4" style="display:center" onclick="window.location.href='../projects/polydec.pdf'">Report (french)</button>
</div>


## Curves & Clouds - A scientific visualization and computing library

A lot a different topics are covered :
  - standard scientific visualization (1D and 2D plots, points clouds, etc...)
  - ODE solvers
  - Dense and Sparse Linear Algebra solvers
  - ML algorithms (Kmeans, PCA, etc...)
  - FEM solvers
  - Quadtree and Delauney Meshing
  - Semi discrete Optimal Transport
  - Symbolic Differentiation -> Geodesic equation solver (used for raytracing around black holes)
  - Discrete Differential Geometry (Heat Geodesic Method, curvatures...)
  - etc...
  
<div style="text-align:center">
<img src="../projects/eigen_laplace.png" style="display:left; margin-left: auto; margin-right: auto;max-width:30%"/>
<img src="../projects/wave.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:37%"/>
<img src="../projects/black_hole.png" style="display:left; margin-left: auto; margin-right: auto;max-width:30%"/>
</div>
<div style="text-align:center">
<img src="../projects/heat_geodesic_method.png" style="display:left; margin-left: auto; margin-right: auto;max-width:28%"/>
<img src="../projects/curvy_rabbit.png" style="display:left; margin-left: auto; margin-right: auto;max-width:28%"/>
<img src="../projects/quadtree_meshing.png" style="display:left; margin-left: auto; margin-right: auto;max-width:28%"/>
</div>


<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='https://github.com/baptiste-genest/CurvesAndClouds/tree/main'">Repo</button>
</div>


## Simple raytracer/sphere-tracer
- raytracing for mesh and bezier surfaces
- sphere tracing for SDF modeling
- basic procedural generation

<div style="text-align:center">
<img src="../projects/utah.jpg" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
<img src="../projects/riemann.jpg" style="display:right; margin-left: auto; margin-right: auto;max-width:33%"/>
<img src="../projects/river.jpg" style="display:right; margin-left: auto; margin-right: auto;max-width:33%"/>
</div>



<img src="boat.gif" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="300" height="">
## Fluid, Solid & Cloth interaction simulation
- Shallow water model for the fluid
- Mass Spring System for the cloth
- Rigid body dynamics for the boat
- (Shitty) Custom 3D rasterization engine for rendering
<br>
<br>
<br>
<br>
<br>

## Misc :

<div style="text-align:center">
</div>
<div style="text-align:center">
<figure>
<img src="../projects/modular_knot.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
<img src="../projects/modular_knot_24.png" style="display:right; margin-left: auto; margin-right: auto;max-width:33%"/>
<figcaption>
Version 2020  --------------------------------- Version 2024


Modular knots, inspired by the amazing article of <a href="https://www.josleys.com/articles/ams_article/Lorenz3.htm">Etienne Ghys & Jos Leys</a>. I will probably write a blog post or do a video about it because it was an amazing 4 year long journey where I often came back to improve the computations gradually. </figcaption>
</figure>
</div>
<div style="text-align:center">
<figure>
<img src="../projects/approximata.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
  <figcaption>Image approximating cellular automata</figcaption>
</figure>
</div>
<div style="text-align:center">

<figure>
<img src="../projects/tree.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
<figcaption>Procedural tree generation</figcaption>
</figure>
</div>

