#include <stdio.h>
#include<stdlib.h>
int main() {
  int *ptr=(int*)malloc(10*4);
  printf("%p\n",ptr);

//   ptr=realloc(ptr,20*4);
//   printf("%p\n",ptr);


  ptr=realloc(ptr,20000*4);
  printf("%p\n",ptr);
  return 0;

/*
Never use the old pointer after realloc() —
always assign it back like this:

temp = realloc(ptr, new_size);
if (temp != NULL)
    ptr = temp;


Otherwise, if realloc() fails, you lose the original memory and cause a memory leak.
*/


}