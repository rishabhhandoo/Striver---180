int findCeil(BinaryTreeNode<int> *root, int X){
    int ans =INT_MAX;
    while(root!=NULL)
    {
        if(root->data<X)
        {
            root=root->right;
        }else if(root->data > X) 
        {
            ans = min(ans,root->data);
            root=root->left;
        }else {
            return root->data;
        }
    }
    return ans==INT_MAX?-1:ans;
}