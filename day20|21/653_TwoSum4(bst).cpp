/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;
    void helper(TreeNode* root)
    {
        if(!root)   return;
        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        //we have our inorder vector
        int l=0;
        int r=inorder.size()-1;
        while(l<r)
        {
            if(inorder[l] + inorder[r]== k)
            {
                return true;
            }else if(inorder[l] + inorder[r]< k)
            {
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};