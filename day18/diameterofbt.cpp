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
    int helper(TreeNode* root,int &maxi)
    {
        if(root==nullptr)
        {
            return 0;    
        }
        
        int lh = helper(root->left,maxi);
        int rh = helper(root->right,maxi);
        maxi=max(maxi,lh+rh);
        
        return 1+ max(lh,rh);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        //do a dfs traversal and then check max depth from left one and right one
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};