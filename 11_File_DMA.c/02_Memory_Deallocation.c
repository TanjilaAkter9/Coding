#include <stdio.h>
#include<stdlib.h>
int main() {
//   int *ptr=(int*)calloc(10,4);
//   ptr++;
//   free(ptr);
//   output: error

  int *ptr=(int*)calloc(10,4);
  int *p=ptr;
  ptr++;
  free(p);


  return 0;
}