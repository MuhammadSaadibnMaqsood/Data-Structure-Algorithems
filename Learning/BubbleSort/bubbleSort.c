#include <stdio.h>

void traversal(int arr[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int arr[], int n) {
    int temp;
    int isSorted;

    for (int i = 0; i < n - 1; i++) {
        isSorted = 1;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }

        if (isSorted) {
            break;
        }
    }
}

int main() {
    int arr[] = {2, 4, 7, 1, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore sorting:");
    traversal(arr, n);

    bubbleSort(arr, n);

    printf("\nAfter sorting:");
    traversal(arr, n);

    return 0;
}
