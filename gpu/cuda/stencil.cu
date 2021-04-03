// only kernel, not fully executable

#define RADIUS 7
#define BLOCK_SIZE 512
__global__ void stencil(int *in, int *out) 
{
    __shared__ int temp[BLOCK_SIZE + 2 * RADIUS];
    int gindex = threadIdx.x + blockIdx.x * blockDim.x;
    int lindex = threadIdx.x + RADIUS;
	
    // Read input elements into shared memory
    temp[lindex] = in[gindex];
    // At both end of a block, the sliding window moves beyond the block boundary.
    // E.g, for thread id = 512, we wiil read in[505] and in[1030] into temp.
    if (threadIdx.x < RADIUS) {
       temp[lindex - RADIUS] = in[gindex - RADIUS];
       temp[lindex + BLOCK_SIZE] = in[gindex + BLOCK_SIZE];
    }
 
   __syncthreads();
    // Apply the stencil
    int result = 0;
    for (int offset = -RADIUS ; offset <= RADIUS ; offset++)
       result += temp[lindex + offset];

    // Store the result
    out[gindex] = result; 
}
