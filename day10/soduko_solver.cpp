class Solution {
public:
    
    bool valid(int k,vector<vector<char>>& board,int i,int j , int n , int m)
    {
        //col check
        for(int z=0;z<n;z++)
        {
            if(board[z][j]==k+'0')
                return false;
        }
        //row check
        for(int z=0;z<m;z++)
        {
            if(board[i][z]==k+'0')
                return false;
        }
        
        //for checking the box
        i=i/3;
        i=i*3;
        j=j/3;
        j=j*3;
        
        for(int x=i;x<i+3;x++)
        {
            for(int y=j;y<j+3;y++)
            {
                // cout<<x<<" "<<y<<endl;
                if(board[x][y]==k+'0')
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    
    bool helper(vector<vector<char>>& board)
    {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k = 1;k<=9;k++)
                    {
                        if(valid(k,board,i,j,9,9))
                        {
                            board[i][j]=k+'0';
                            if(helper(board)==true)
                            {
                                return true;
                            }else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
       
        int n = board.size();
        int m = board[0].size();
           
        helper(board);
    }
};