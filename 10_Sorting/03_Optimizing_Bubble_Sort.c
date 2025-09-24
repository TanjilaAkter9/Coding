#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;  // reset at start of each pass
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;   // swap happened
            }
        }
        if (flag == false)  // no swaps = array sorted
            break;
    }
}

int main() {
    int a[] = {7, 4, 2, 8, 3};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    printf("Bubble sorted:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
/*
Time complexity:
Best O(n)
Avg O(n^2)
Worst O(n^2)

*/