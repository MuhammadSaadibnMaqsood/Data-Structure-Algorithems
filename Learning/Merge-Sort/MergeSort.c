#include <stdio.h>

void traversal(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++)
    {
        arr[low + x] = temp[x];
    }
}

void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {2, 4, 7, 1, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nBefore sorting:");
    traversal(arr, n);

    MergeSort(arr, 0, n - 1);

    printf("\nAfter sorting:");
    traversal(arr, n);

    return 0;
}
