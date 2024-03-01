---
title: "Projects"

---

<div style="text-align:center">

Here is a selection of my favorite and most polished projects/experiments over the last 4 years.

For me, loving Math & Computer Science is an endless source of discoveries and joy. 
</div>

##  "Estimation of the volume of Voronoi cells in high dimension and control variables in Monte Carlo rendering"

- Exploration of stochastic techniques in estimating the volume and barycenters of Voronoi cells in high dimension
- Improvement of Monte Carlo integration by control variate techniques, new control variate proposed
- Caracterization and proofs of domination of the new control variate over the original control variate

<div style="text-align:center">
<img src="../projects/vorayce.png" style="display:block; margin-left: auto; margin-right: auto;max-width:80%" alt="NESOTS trailer" />
Supervised by David Coeurjolly and Vincent Nivoliers
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

## Internship : Use of Normal information to improve differential operators on polygonal meshes  
- Various Spline based approaches to provide better estimates of non-linear edges in order improve the convergence of discretizations of differential operators based on [Fernando De Goes et al.](https://graphics.pixar.com/library/PolyDDG/paper.pdf)
 (No conclusive results)
<div style="text-align:center">
<img src="../projects/embedder.png" style="display:block; margin-left: auto; margin-right: auto;max-width:80%" alt="NESOTS trailer" />
Supervised by David Coeurjolly
<button class="button-4" style="display:center" onclick="window.location.href='../projects/polydec.pdf'">Report (french)</button>
</div>

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
  - etc...
  
<div style="text-align:center">
<img src="../projects/eigen_laplace.png" style="display:left; margin-left: auto; margin-right: auto;max-width:30%"/>
<img src="../projects/wave.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:37%"/>
<img src="../projects/black_hole.png" style="display:left; margin-left: auto; margin-right: auto;max-width:30%"/>
</div>


<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='https://github.com/baptiste-genest/CurvesAndClouds/tree/main'">Repo</button>
</div>

<img src="stable_fluids.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="250" height="">
## Stable Fluids implementation   
Standard [Stable Fluids](https://www.ljll.math.upmc.fr/~frey/cours/references/Stam%20J.,%20Stable%20fluids.pdf) implementation :
  - Diffusion
  - Semi-Lagrangian advection
  - Projection method with prefactored sparse laplacian matrix for poisson problem 
  $$\Delta u = \nabla \cdot v$$

## BSP-OT

Computes very fast (in quasilinear time) an assignation that is a good approximation of the optimal one. (Sadly, it has already been [published](https://arxiv.org/abs/1912.02317)). It works really well when the optimality is not as important as speed such as in color transfer.

<div style="text-align:center">
<img src="../projects/BSPOT_plan.png" style="display:left; margin-left: auto; margin-right: auto;max-width:35%"/>
<img src="../projects/BSPOT_color.png" style="display:right; margin-left: auto; margin-right: auto;max-width:60%"/>
</div>

<img src="forest_fire.gif" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="350" height="">
## Forest Fire simulation by coupled discrete stochastic processes

- Simple discrete model
- Geometric laws of growth.
- Some interesting properties, for instance fire can disappear completely and come back later due to spreading. 
- very tunable and upgradable
<div style="text-align:center">
<button class="button-4" style="display:center" onclick="window.location.href='./forest_fire.cpp'">Code</button>
</div>
<br>
<br>

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
<br>

<img src="road_gen.png" style="display: block; float:right;
           margin-left: auto;
           margin-right: auto;" alt= “” width="300" height="">
## Road Generation
- A* algorithm for the main track, with weights on the vertices and on the edges to avoid
height difference
- then, to get closer to a clothoïd, since they have affine curvature, I use a crude approximation by minimizing the energy :
$$
\mathcal{E}(\gamma) = \int_0^1 ||\gamma^{(4)}(t)||^2 dt
$$
with an implicit scheme.

## Simple raytracer/sphere-tracer
- raytracing for mesh and bezier surfaces
- sphere tracing for SDF modeling
- basic procedural generation

<div style="text-align:center">
<img src="../projects/utah.jpg" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
<img src="../projects/riemann.jpg" style="display:right; margin-left: auto; margin-right: auto;max-width:33%"/>
<img src="../projects/river.jpg" style="display:right; margin-left: auto; margin-right: auto;max-width:33%"/>
</div>

## Misc :
Modular knot, inspired by the amazing article of [Etienne Ghys & Jos Leys](https://www.josleys.com/articles/ams_article/Lorenz3.htm) 
<div style="text-align:center">
<img src="../projects/modular_knot.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
</div>
Image approximating cellular automata
<div style="text-align:center">
<img src="../projects/approximata.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
</div>
Procedural tree generation
<div style="text-align:center">
<img src="../projects/tree.gif" style="display:left; margin-left: auto; margin-right: auto;max-width:33%"/>
</div>

