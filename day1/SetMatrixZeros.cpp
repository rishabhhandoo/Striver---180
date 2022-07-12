class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        bool rcheck=0;
        bool ccheck=0;
        
        //for first row
        for(int i=0;i<col;i++)
        {
            if(matrix[0][i]==0){
                rcheck=1;
                break;
            }
        }
        //for first col
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0){
                ccheck=1;
                break;
            }
        }
        cout<<ccheck;
        
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;                    
                }
            }
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        
        //setting row
        if(rcheck==1)
           for(int i=0;i<col;i++)
                matrix[0][i]=0;
        if(ccheck==1)
            for(int j=0;j<row;j++)
                matrix[j][0]=0;
        
    }
};