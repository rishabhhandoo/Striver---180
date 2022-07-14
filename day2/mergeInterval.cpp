class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if(intervals.size()==1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        int strt = intervals[0][0];
        int end = intervals[0][1];
        temp.push_back(strt);
        temp.push_back(end);

        for (int i = 0; i < intervals.size(); i++)
        {
            cout<<"value of i "<<i<<endl;
            if(merge(temp,intervals[i])){
                strt = min(strt, intervals[i][0]);
                end = max(end, intervals[i][1]);
                temp[0] = strt;
                temp[1] = end;
                cout<<"1st "<<strt<<" "<<end<<endl;
            }
            else{
                ans.push_back(temp);
                strt=intervals[i][0];
                end=intervals[i][1];
                temp[0] = strt;
                temp[1] = end;
                cout<<"2nd "<<strt<<" "<<end<<endl;

            }
        }
        ans.push_back(temp);
        
        return ans;
    }
    bool merge(vector<int> t1,vector<int> t2)
    {
        if(t1[1]>=t2[0])    return true;
        else return false;
    }
};