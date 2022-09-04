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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long ans=0;
        int level=0;
        q.push({root,level});
               
               while(!q.empty())
               {
                   int sz = q.size();
                   long long mn=INT_MAX;
                   long long mx=INT_MIN;
                   while(sz--)
                   {
                       int ind = q.front().second;
                       mn = min(q.front().second,mn);
                       mx = max(q.front().second,mx);
                       TreeNode* curr = q.front().first;
                       q.pop();
                       if(curr->left)
                       {
                           q.push({curr->left,(2*(ind-mn))+1});
                       }
                       if(curr->right)
                       {
                            q.push({curr->right,(2*(ind-mn))+2});
                       }
                   }
                   ans=max(ans,mx-mn+1);
                   cout<<ans<<endl;
                   
               }
        
        return ans;
    }
};