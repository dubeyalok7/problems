#include <stdio.h>

__global__ void mykernel(void) {
  while(1)
    printf("Hello kernel\n");
}

int main(void) {
  mykernel<<<222,222>>>();
  while(1)
  printf("Hello World!\n");
  return 0;
}
