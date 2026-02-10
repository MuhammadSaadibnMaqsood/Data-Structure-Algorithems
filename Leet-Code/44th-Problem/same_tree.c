bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    // Both null → same
    if (p == NULL && q == NULL)
        return true;

    // One null → not same
    if (p == NULL || q == NULL)
        return false;

    // Values differ
    if (p->val != q->val)
        return false;

    // Check left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
