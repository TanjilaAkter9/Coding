//Preprocessor directive
#include <stdio.h>
//# is the preprocessor,the rest is directive
#include<stdlib.h>
int main() {

    // int *ptr=(int*)malloc(100*sizeof(int));
    // char *pointer=(char*)malloc(100*sizeof(char));

    // printf("%d",*ptr);//garbage values


    //Take n numbers and display them
    int n;
    scanf("%d",&n);
    int *ptr=(int*)malloc(10*sizeof(int));
    int *p=ptr;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&(*ptr));
        ptr++;

    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",(*p));
        p++;
    }

    //int *ptr=NULL;
    //Output=0x0 (address)\
    

           
// | Expression | Meaning                                               |
// | ---------- | ----------------------------------------------------- |
// | `ptr`      | The address (pointer)                                 |
// | `*ptr`     | The value stored at that address                      |
// | `&ptr`     | The address **of the pointer variable itself**        |
// | `&(*ptr)`  | Same as `ptr` (because `*` and `&` cancel each other) |

    


  
  return 0;
}