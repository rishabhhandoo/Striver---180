bool dfs(vector<int> &ans,TreeNode* root, int b)
{
    if(root==NULL)
    {
        return false;
    }   
    ans.push_back(root->val);
    if(root->val == b)  return true;
    
    if(dfs(ans,root->left,b)||dfs(ans,root->right,b))   return true;
    
    ans.pop_back();
    return false; 
}
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> ans;
    bool hmm = dfs(ans,A,B);
    return ans;
    
    
}
