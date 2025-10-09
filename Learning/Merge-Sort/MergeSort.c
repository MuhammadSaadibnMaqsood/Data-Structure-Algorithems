#include <stdio.h>

void traversal(int arr[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}



int main() {
    int arr[] = {2, 4, 7, 1, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore sorting:");
    traversal(arr, n);

    MergeSort(arr, n);

    printf("\nAfter sorting:");
    traversal(arr, n);

    return 0;
}
