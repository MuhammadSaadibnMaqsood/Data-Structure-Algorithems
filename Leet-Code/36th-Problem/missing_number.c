int missingNumber(int* nums, int numsSize)
{
    int total = 0;
    for (int i = 0; i <= numsSize; i++)
    {
        total += i;
    }

    int nums_total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        nums_total += nums[i];
    }

    return total - nums_total;
}
