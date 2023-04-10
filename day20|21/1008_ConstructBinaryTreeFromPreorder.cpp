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
    int i=0;
    TreeNode* helper(vector<int>& preorder,int ub)
    {
        if(i>=preorder.size() || preorder[i]>ub)  return NULL;

        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = helper(preorder,node->val);
        node->right = helper(preorder,ub);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,INT_MAX);
    }
};