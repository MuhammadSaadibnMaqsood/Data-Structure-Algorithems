#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr[] = (int *)malloc(2 * sizeof(int));

    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
}