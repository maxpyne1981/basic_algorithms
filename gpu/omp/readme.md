### openmp: how to build
icc -qopenmp hello.cpp
./a.out

### references
- [pdf tutorial](https://people.math.umass.edu/~johnston/PHI_WG_2014/OpenMPSlides_tamu_sc.pdf) 
## notes
- openmp uses fork - join model, 

- shared variables - shared by all thredas
- private - only visible to the thread, 
- #pragma omp parallel for 
- dividing loop into fixed sized portions : static scheduling
- some times it is not a good idea, load imbalance, some threads take too long to finish, others are waiting to join, 
- alternate is dynamic scheduling, but large overhead,
- data dependencies: read after write, write after read, read after read, 
- firstprivate: private but initialized to the value prior to parelle region, 
- nowait: do not wait for sync and of parellel region, 
- critical: only one thread operates on the block, 
- atomic: for atomic operations
- barrier: all threads need to sync before moving fwd, 
- #pragma omp parallel if(n>100000) : convenient way to trigger omp parallelism
- 
- 

