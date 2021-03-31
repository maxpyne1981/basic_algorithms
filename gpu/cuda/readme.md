# ref materials
1. cuda tutorial [ref](https://developer.nvidia.com/blog/even-easier-introduction-cuda/)
2. cuda refresher [ref](https://developer.nvidia.com/blog/tag/cuda-refresher/)

# build and run
nvcc vectoradd.cu -o exec
./exec

# run profiler (not working yet)
nvprof --unified-memory-profiling off ./exec

# things to remember
1. usm, cudaMallocManaged(&x, N*sizeof(float));
2. cudaDeviceSynchronize();


