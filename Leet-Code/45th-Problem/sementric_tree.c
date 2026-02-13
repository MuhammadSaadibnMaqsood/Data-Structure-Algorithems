bool isMatch(struct TreeNode* left, struct TreeNode* right){
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val != right->val) return false;

    return isMatch(left->left, right->right) &&
           isMatch(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;

    return isMatch(root->left, root->right);
}
