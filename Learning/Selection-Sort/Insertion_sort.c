#include <stdio.h>

void traversal(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int n)
{

    int min;
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 5, 8, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    printf("\nBefore sorting");
    traversal(arr, n);

    selectionSort(arr, n);

    printf("\nAfter sorting");
    traversal(arr, n);

    return 0;
}
