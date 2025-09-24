#include <stdio.h>
void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
    }
}

int main() {
    int a[]={6,2,8,3,1,9};
    int n=sizeof(a)/sizeof(a[0]);
    
    bubbleSort(a,n);
    
    printf("Bubble sorted:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }


  return 0;
}
