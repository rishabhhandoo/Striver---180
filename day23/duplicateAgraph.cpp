/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node* curr,Node* node,vector<Node*> &vis)
    {
        vis[node->val]=node;
        
        for(auto ele:curr->neighbors)
        {
            if(vis[ele->val]==nullptr)
            {
                Node* newnode = new Node(ele->val);
                (node->neighbors).push_back(newnode);
                dfs(ele,newnode,vis);
            }
            else{
                (node->neighbors).push_back(vis[ele->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) 
                return nullptr;
        
        Node* copy = new Node(node->val);
        vector<Node*> vis(101,NULL);
        vis[node->val] = copy;
        for(auto itr:node->neighbors)
        {
            if(vis[itr->val] == nullptr)
            {
                Node* newnode = new Node(itr->val);
                copy->neighbors.push_back(newnode);
                dfs(itr,newnode,vis);
            }else{
                copy->neighbors.push_back(vis[itr->val]);
            }
        }
        
        return copy;
    }
};