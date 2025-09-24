#include <stdio.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];   // current element
        int j = i - 1;

        // shift elements greater than key to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key; // place key at correct position
    }
}

int main() {
    int a[] = {7, 4, 2, 8, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    printf("Insertion sorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
