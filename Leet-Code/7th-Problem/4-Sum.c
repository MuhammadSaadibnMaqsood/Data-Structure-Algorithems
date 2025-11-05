#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long diff = (long long)(*(int *)a) - (long long)(*(int *)b);
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare); // sort to handle duplicates

    int maxResults = numsSize * numsSize;
    int **result = (int **)malloc(maxResults * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxResults * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

            for (int k = j + 1; k < numsSize - 1; k++)
            {
                if (k > j + 1 && nums[k] == nums[k - 1]) continue; // skip duplicate k

                for (int l = k + 1; l < numsSize; l++)
                {
                    if (l > k + 1 && nums[l] == nums[l - 1]) continue; // skip duplicate l

                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        result[*returnSize] = (int *)malloc(4 * sizeof(int));
                        result[*returnSize][0] = nums[i];
                        result[*returnSize][1] = nums[j];
                        result[*returnSize][2] = nums[k];
                        result[*returnSize][3] = nums[l];
                        (*returnColumnSizes)[*returnSize] = 4;
                        (*returnSize)++;
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    int nums[] = {1000000000, 1000000000, 1000000000, 1000000000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;

    int returnSize;
    int *returnColumnSizes;

    int **result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(",");
        }
        printf("]");
        if (i < returnSize - 1)
            printf(",");
    }
    printf("]\n");

    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}
