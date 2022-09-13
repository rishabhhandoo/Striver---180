vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    sort(a.begin(),a.end(),greater<int> ());
    sort(b.begin(),b.end(),greater<int> ());

    vector<int> ans;
    set<pair<int,int>> vis;
    
    priority_queue<pair<int,pair<int,int>> >pq;
    
    pq.push( {a[0]+b[0],{0,0}} );
    vis.insert({0,0});
    
    for(int i=0;i<c;i++)
    {
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        if(p.second.first+1<a.size() && vis.find({p.second.first+1,p.second.second}) == vis.end() ) 
        {
            pq.push({a[p.second.first+1] + b[p.second.second],{p.second.first+1,p.second.second}});
            vis.insert({p.second.first+1,p.second.second});
        }
        
        if(p.second.second+1<a.size() && vis.find({p.second.first,p.second.second+1}) == vis.end() ) 
        {
            pq.push({a[p.second.first] + b[p.second.second+1],{p.second.first,p.second.second+1}});
            vis.insert({p.second.first,p.second.second+1});
        }
        
    }
    return ans;
}
