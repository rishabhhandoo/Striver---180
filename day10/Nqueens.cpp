class Solution {
public:
    bool possible(vector<int> &col,vector<int> &diag,int row,int i)
    {
        int temp1=row;
        int temp2=i;
        
        if(col[i]==1)
            return false;
        //--
        while(temp1>0 && temp2 >0)
        {
            cout<<"diag --"<<endl;
            temp1--;
            temp2--;
            if(temp2==diag[temp1])
                return false;
        }
        
        temp1=row;
        temp2=i;
        while(temp1>0 && temp2 >=0)
        {
            cout<<"diag -+"<<endl;

            temp1--;
            temp2++;
            if(temp2==diag[temp1])
                return false;
        }
        cout<<"passsed"<<row<<" "<<i<<endl;
        return true;
        
    }
    
    
    void helper(int row,vector<string> board,vector<vector<string>> &ans,vector<int> diag,vector<int> col,int n)
    {
        //base case
        if(row>=n)
        {
            ans.push_back(board);
            return;
        }
        
        // int flag = false;
        for(int i=0;i<n;i++)
        {
            cout<<row<<" "<<i<<endl;
            if(possible(col,diag,row,i))
            {
    
                cout<<row<<" due to this"<<i<<endl;
                board[row][i]='Q';
                //col + diagcheck new addn
                col[i]=1;
                diag[row]=i;
                helper(row+1,board,ans,diag,col,n);
                col[i]=0;
                diag[row]=-1;
                board[row][i]='.';
            }
        }
        return;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        string addn="";
        for(int i=0;i<n;i++)
        {
            addn+='.';
        }
        vector<string> thisrow(n,addn);
        vector<vector<string>> ans;
        
        int row=0;
        
        //index storage
        vector<int> diag(n,-1);
        vector<int> col(n,0);
        helper(row,thisrow,ans,diag,col,n);
        return ans;
    }
};