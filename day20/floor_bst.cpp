int floorInBST(TreeNode<int> * root, int X)
{
    int ans =0;
    while(root!=NULL)
    {
        if(root->val>X)
        {
            root=root->left;
        }else if(root->val < X) 
        {
            ans = max(ans,root->val);
            root=root->right;
        }else {
            return root->val;
        }
    }
    return ans;
}