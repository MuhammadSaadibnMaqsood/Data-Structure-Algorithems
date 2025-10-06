#include <stdio.h>

void traversal(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 1, 4, 5, 3};
    int n = sizeof(arr) / sizeof(int);

    printf("\nBefore sorting:");
    traversal(arr, n);

    insertionSort(arr, n);

    printf("\nAfter sorting:");
    traversal(arr, n);

    return 0;
}
