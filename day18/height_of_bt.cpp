int helper(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lh = helper(root->left);
    int rh = helper(root->right);
    // maxi=max(maxi,lh+rh);

    return 1 + max(lh, rh);
}