#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#define N 512

__global__ void add(int *a, int *b, int *c){
  c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x];
}

int main(void) {
  int *a, *b, *c;
  int *da, *db, &dc;
  int size = N *sizeof(int);

  //Alloc space for device copies of a,b, c
  cudaMalloc((void **)&da, size);
  cudaMalloc((void **)&db, size);
  cudaMalloc((void **)&dc, size);

  //Alloc space for host copies of a, b, c and setup input values
  a = (int *)malloc(size); random_ints(a, N);
  b = (int *)malloc(size); random_ints(b, N);
  c = (int *)malloc(size);

  //Copy inputs to device
  cudaMemcpy(da, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(db, b, size, cudaMemcpyHostToDevice);

  //Launch add() kernel on GPU with N blocks
  add<<<N, 1>>>(da, db, dc);

  //Copy result back to host
  cudaMemcpy(c, dc, size, cudaMemcpyDeviceToHost);

  free(a); free(b); free(c);
  cudaFree(da); cudaFree(db); cudaFree(dc);
  return 0;
}
