#include <stdio.h>

void traversal(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = 0;
    int j = high;

    do
    {
        while (pivot > arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    } while (i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void QuickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low > high)
    {
        partitionIndex = partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {2, 4, 7, 1, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore sorting:");
    traversal(arr, n - 1);

    QuickSort(arr, 0, n - 1);

    printf("\nAfter sorting:");
    traversal(arr, n);

    return 0;
}
