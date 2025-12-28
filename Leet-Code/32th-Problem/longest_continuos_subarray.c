#include <stdlib.h>

int longestSubarray(int* nums, int numsSize, int limit) {
    int* maxDeque = (int*)malloc(numsSize * sizeof(int));
    int* minDeque = (int*)malloc(numsSize * sizeof(int));

    int maxFront = 0, maxBack = 0;
    int minFront = 0, minBack = 0;

    int left = 0;
    int result = 0;

    for (int right = 0; right < numsSize; right++) {

        // Maintain decreasing deque for max
        while (maxBack > maxFront && nums[maxDeque[maxBack - 1]] < nums[right])
            maxBack--;
        maxDeque[maxBack++] = right;

        // Maintain increasing deque for min
        while (minBack > minFront && nums[minDeque[minBack - 1]] > nums[right])
            minBack--;
        minDeque[minBack++] = right;

        // Shrink window if invalid
        while (nums[maxDeque[maxFront]] - nums[minDeque[minFront]] > limit) {
            left++;
            if (maxDeque[maxFront] < left) maxFront++;
            if (minDeque[minFront] < left) minFront++;
        }

        // Update result
        int windowSize = right - left + 1;
        if (windowSize > result)
            result = windowSize;
    }

    free(maxDeque);
    free(minDeque);
    return result;
}
