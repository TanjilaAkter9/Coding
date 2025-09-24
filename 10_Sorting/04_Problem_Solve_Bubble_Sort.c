//Make bubble sort algorithm resulting in decending order
#include <stdio.h>
#include<stdbool.h>
void bubble_sort_descending(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool flag=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                flag=true;
            }
        }
        if(flag==false) break;
    }
}
int main() {
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    
    bubble_sort_descending(a,n);

    printf("Bubble sorted descending:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
  
  return 0;
}