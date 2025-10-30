#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (abs(sum - target) < abs(closestSum - target))
                closestSum = sum;

            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return sum; 
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    int result = threeSumClosest(nums, numsSize, target);
    printf("Closest sum: %d\n", result);
    return 0;
}
