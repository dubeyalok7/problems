#include <stdio.h>

__global__ void mykernel(void) {
  printf("Hello kernel\n");
}

int main(void) {
  mykernel<<<2,2>>>();
  printf("Hello World!\n");
  return 0;
}
