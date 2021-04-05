# ref materials
1. cuda tutorial [ref](https://developer.nvidia.com/blog/even-easier-introduction-cuda/)
2. cuda refresher [ref](https://developer.nvidia.com/blog/tag/cuda-refresher/)
3. cuda shared memory [ref](https://developer.nvidia.com/blog/using-shared-memory-cuda-cc/)
4. quick tutorial [ref](https://jhui.github.io/2017/03/06/CUDA/)


# quick facts
- GeoForce 8800 with 16 SMs each with 8 core, 
- each SM processes each block of same kernel, 
- Pascal GP100 can handle maximum of 32 thread blocks and 2048 threads per SM.
- most SM supports (1024, 1024, 1024) threads in each dim, but total threads per SM is 1024
- max grid (65635, 65635, 65635) per dim, but total 65635,
- threds in a block runs as WARP of 32 threads, 


# memory declaration and scope,
Declaration	Memory	Scope	Lifetime
int v	register	thread	thread
int vArray[10]	local	thread	thread
__shared__ int sharedV	shared	block	block
__device__ int globalV	global	grid	application
__constant__ int constantV	constant	grid	application

# build and run
nvcc vectoradd.cu -o exec
./exec

# kernel
kernel<<<number of blocks, number of threads per block>>>

# difference with cpu
cpu : low latency,
gpu : high throughput, hides latency by running throusands of concurrant threads,

# run profiler (not working yet)
nvprof --unified-memory-profiling off ./exec
sudo /usr/local/cuda-10.1/bin/nvprof ./exec

# things to remember
1. usm, cudaMallocManaged(&x, N*sizeof(float));
2. cudaDeviceSynchronize();
- cudaMemcpy(d_d, a, n*sizeof(int), cudaMemcpyHostToDevice);
- cudaMemcpy(d, d_d, n*sizeof(int), cudaMemcpyDeviceToHost);
- cudaMalloc(&d_d, n * sizeof(int));


# grid, block thread all 0 based indices

# example of vector add kernel
'''
__global__ void vectorAdd( float *A, float *B, float *C, int numElements) {
  int i = blockDim.x * blockIdx.x + threadIdx.x;
  if (i < numElements) {
    C[i] = A[i] + B[i];
  }
}
'''
# key concepts
- CUDA blocks : collection or group  of threads.
- Shared memory : memory shared within a block among all threads.
- Synchronization barriers : Enable multiple threads to wait until all threads have reached a particular point of execution before any thread continues.

- shared memoty is 100x faster than global memory

# types of gpus
- GeForce GPUs for gaming and notebooks
- Quadro GPUs for professional visualization
- Datacenter GPUs
- Tegra for embedded SoCs


# hw spec
- max threads per block : 1024
- ( sm -> registers -> L1 cache ) -> L2 cache ( A100/40MB ) -> global memory (DRAM/40MB) 

# nvprof report
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
 GPU activities:  100.00%  101.76ms         1  101.76ms  101.76ms  101.76ms  add_gpu(int, float*, float*)
      API calls:   65.74%  271.02ms         1  271.02ms  271.02ms  271.02ms  cudaProfilerStart
                   24.68%  101.76ms         1  101.76ms  101.76ms  101.76ms  cudaDeviceSynchronize
                    9.32%  38.433ms         1  38.433ms  38.433ms  38.433ms  cudaDeviceReset
                    0.11%  440.15us         2  220.08us  205.09us  235.06us  cudaFree
                    0.06%  231.28us        97  2.3840us     202ns  97.920us  cuDeviceGetAttribute
                    0.06%  230.45us         1  230.45us  230.45us  230.45us  cuDeviceTotalMem
                    0.02%  69.718us         2  34.859us  9.1720us  60.546us  cudaMallocManaged
                    0.01%  34.382us         1  34.382us  34.382us  34.382us  cuDeviceGetName
                    0.01%  25.617us         1  25.617us  25.617us  25.617us  cudaLaunchKernel
                    0.00%  3.5530us         1  3.5530us  3.5530us  3.5530us  cuDeviceGetPCIBusId
                    0.00%  1.6000us         2     800ns     350ns  1.2500us  cuDeviceGetCount
                    0.00%     896ns         1     896ns     896ns     896ns  cudaProfilerStop
                    0.00%     637ns         2     318ns     232ns     405ns  cuDeviceGet
                    0.00%     332ns         1     332ns     332ns     332ns  cuDeviceGetUuid


### how to debug cuda workflow
- [video tutorials](https://www.youtube.com/watch?v=ENerb1HO6zs)
- race condition, 
- deadlocks, 
- shared mempry level / race condition bugs, 
- only warps are executed simultaneously,
- shared / device memory, use atomicadd
- use -G -g hodet and cuda debugging 
- very difficulti to debug  following two bug types 
- race condition bugs show up at optimized code, 
- out of resource allocation, 
- 


