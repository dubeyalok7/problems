#include <stdio.h>
#include <cuda.h>

__global__ void myKernel(int *d_arr) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    d_arr[idx] = d_arr[idx]*2;
}

int main(void) {
    int *h_arr, *d_arr;
    h_arr = (int *)malloc(10*sizeof(int));
    for (int i=0; i<10; ++i)
        h_arr[i] = i; // Or other values

    // Sends data to device
    cudaMalloc((void**) &d_arr, 10*sizeof(int));
    cudaMemcpy(d_arr, h_arr, 10*sizeof(int), cudaMemcpyHostToDevice);

    // Runs kernel on device
    myKernel<<< 2, 5 >>>(d_arr);

    // Retrieves data from device
    cudaMemcpy(h_arr, d_arr, 10*sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i<10; ++i)
        printf("Post kernel value in h_arr[%d] is: %d\n", i,h_arr[i]);

    cudaFree(d_arr);
    free(h_arr);
    return 0;
}
