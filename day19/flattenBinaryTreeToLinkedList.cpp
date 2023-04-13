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
    TreeNode* prev = nullptr;
    void helper(TreeNode* root)
    {
        if(root==NULL)   return;
        helper(root->right);
        helper(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
        return;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};