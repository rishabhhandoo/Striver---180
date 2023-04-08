class Solution {
public:
    vector<int> temp;
    void helper(TreeNode* root)
    {
        if(root==NULL)  return;

        helper(root->left);
        temp.push_back(root->val);
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        //doing inorder traversal   
        helper(root);
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]<=temp[i-1])  return false;
        }
        return true;
    }
};