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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
       if(root==NULL) return ans;
        queue<TreeNode*> q;
        
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int num = q.size();
            vector<int> levels(num);
            
            for(int i=0;i<num;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
                int index = (flag==true)?i:num-1-i;
                
                levels[index] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            flag=!flag;
            ans.push_back(levels);
        }
    return ans;
    }
};