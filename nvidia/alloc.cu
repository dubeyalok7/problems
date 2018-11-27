#include <stdio.h>
#include <cuda_runtime_api.h>
#include <cuda.h>

__global__ void add(int *a, int *b, int *c)
{
  *c = *a + *b;
}

int main(void)
{
  int a, b, c;
  int *d_a, *d_b, *d_c;
  int size = sizeof(int);

  //Allocate space for device copies of a, b, c
  cudaMalloc((void**)&d_a, size);
  cudaMalloc((void**)&d_b, size);
  cudaMalloc((void**)&d_c, size);

  a = 2;
  b = 7;

  //copy inputs to device
  cudeMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
  cudeMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

  add<<<1,1>>>(d_a, d_b, d_c);

  //copy result back to host
  cudeMemcpy(&c, d_c, cudaMemcpyDeviceToHost);

  //cleanup
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}
