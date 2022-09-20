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
    
    int helper(TreeNode* root,bool &ans)
    {
        if(root==nullptr)
        {
            return 0;
        }
        
        int lh = helper(root->left,ans)+1;
        int rh = helper(root->right,ans)+1;
        
        if(abs(lh-rh) >=2)
            ans=ans&false;
        
        return max(lh,rh);
            
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        helper(root,ans);
        return ans;
    }
};