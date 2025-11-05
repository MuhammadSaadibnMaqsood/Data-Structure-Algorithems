#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int k = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main(int argc, char const *argv[])
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    int k = removeElement(nums, numSize, val);

    printf("\n%d", k);

    return 0;
}
