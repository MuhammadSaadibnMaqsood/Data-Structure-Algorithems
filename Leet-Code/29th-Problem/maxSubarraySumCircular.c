#include <stdio.h>

int maxSubarraySumCircular(int *nums, int numsSize)
{
    int totalSum = 0;

    int maxEnding = nums[0], maxSoFar = nums[0];
    int minEnding = nums[0], minSoFar = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        totalSum += nums[i];

        if (i > 0)
        {
            maxEnding = (nums[i] > maxEnding + nums[i]) ? nums[i] : maxEnding + nums[i];
            maxSoFar = (maxSoFar > maxEnding) ? maxSoFar : maxEnding;

            minEnding = (nums[i] < minEnding + nums[i]) ? nums[i] : minEnding + nums[i];
            minSoFar = (minSoFar < minEnding) ? minSoFar : minEnding;
        }
    }

    // If all numbers are negative
    if (maxSoFar < 0)
        return maxSoFar;

    // Max of normal and circular
    int circularMax = totalSum - minSoFar;
    return (maxSoFar > circularMax) ? maxSoFar : circularMax;
}
