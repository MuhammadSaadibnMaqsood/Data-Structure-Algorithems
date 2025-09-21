#include <stdio.h>
int linearSearch(int arr[], int size, int el)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == el)
        {
            return i;
        }
    }

    return -1;
}
int binarySearch(int arr[], int size, int el)
{
    int low, high, mid;
    high = size - 1;
    low = 0;
    mid = (low + high) / 2;

    while (low <= high)
    {
        if (arr[high] == el)
        {
            return high;
        }
        if (arr[low] == el)
        {
            return low;
        }

        if (arr[mid] == el)
        {
            return mid;
        }

        if (arr[mid] > el)
        {
            high = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {

            low = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(arr) / sizeof(int);
    int el = 18;

    int foundIndexLinear = linearSearch(arr, size, el);

    printf("\n%d element found from linear search on index %d\n", el, foundIndexLinear);

    int foundIndexBinary = binarySearch(arr, size, el);
    printf("\n%d element found from binary search on index %d\n", el, foundIndexBinary);

    return 0;
}
