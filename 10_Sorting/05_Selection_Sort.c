#include <stdio.h>
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minIndex] > a[j])
                minIndex = j;
        }

        // swap
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;

        // simple print after each pass
        printf("%d swapped with %d\n", a[minIndex], a[i]);
        printf("After pass %d: ", i + 1);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}

int main()
{
    int a[] = {7, 4, 2, 8, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);

    printf("\nFinal sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
