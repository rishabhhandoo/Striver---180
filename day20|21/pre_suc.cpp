void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==nullptr)   return ;
    findPreSuc(root->left,pre,suc,key);
    if(root->key<key )
    {
        if(pre==NULL || root->key>pre->key)
            pre=root;
    }
    if(root->key>key )
    {
        if(suc==NULL || root->key<suc->key)
            suc=root;
    }
    findPreSuc(root->right,pre,suc,key);
    return ;
}