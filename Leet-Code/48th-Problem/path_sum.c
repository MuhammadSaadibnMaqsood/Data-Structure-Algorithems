
void dfs(struct TreeNode* root,
         int targetSum,
         int currentSum,
         int* path,
         int pathLen,
         int*** result,
         int* returnSize,
         int** returnColumnSizes) {

    if (!root) return;

    path[pathLen] = root->val;
    currentSum += root->val;
    pathLen++;

    if (!root->left && !root->right && currentSum == targetSum) {

        (*result)[*returnSize] = (int*)malloc(pathLen * sizeof(int));

        for (int i = 0; i < pathLen; i++) {
            (*result)[*returnSize][i] = path[i];
        }

        (*returnColumnSizes)[*returnSize] = pathLen;
        (*returnSize)++;
    }

    // Recurse left and right
    dfs(root->left, targetSum, currentSum, path, pathLen,
        result, returnSize, returnColumnSizes);

    dfs(root->right, targetSum, currentSum, path, pathLen,
        result, returnSize, returnColumnSizes);
}

int** pathSum(struct TreeNode* root,
              int targetSum,
              int* returnSize,
              int** returnColumnSizes) {

    *returnSize = 0;

    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int maxNodes = 5000;

    int** result = (int**)malloc(maxNodes * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxNodes * sizeof(int));

    int path[5000]; 

    dfs(root, targetSum, 0, path, 0,
        &result, returnSize, returnColumnSizes);

    return result;
}
