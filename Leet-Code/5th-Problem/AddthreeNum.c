#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    
    int maxTriplets = numsSize * numsSize;
    int** result = (int**)malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxTriplets * sizeof(int));
    *returnSize = 0;

    
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                
                int lastLeft = nums[left];
                int lastRight = nums[right];
                while (left < right && nums[left] == lastLeft) left++;
                while (left < right && nums[right] == lastRight) right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }

    return result;
}



int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int *returnColumnSizes;

    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    // Print output
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(",");
        }
        printf("]");
        if (i < returnSize - 1)
            printf(",");
    }
    printf("]\n");

    // Free memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}
