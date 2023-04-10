class Solution {
public:
    Node* connect(Node* root) {
        //doing a bfs and pointing the next to right one
        //parent and root
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            Node* rnode=NULL;
            for(int i=sz;i>0;i--)
            {
                Node* curr= q.front();
                q.pop();
                curr->next=rnode;
                if(curr->right)
                {
                    q.push(curr->right);
                    q.push(curr->left);
                }
                rnode=curr;
            }
        }
        return root;
    }
};