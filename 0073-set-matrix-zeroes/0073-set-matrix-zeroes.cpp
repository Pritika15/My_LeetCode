class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // pair<int,int>LocZero;
        vector<pair<int,int>>v;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back({i,j});
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        
        for(int i=0;i<v.size();i++)
        {
            int r=v[i].first;
            int c=v[i].second;
            
            int rvar=r;
            while(rvar!= -1)
            {
                matrix[rvar][c]=0;
                rvar--;
            }
            
            rvar=r;
            while(rvar<matrix.size())
            {
               matrix[rvar][c]=0;
                rvar++;
            }
            
            int cvar=c;
            while(cvar!= -1)
            {
                matrix[r][cvar]=0;
                cvar--;
            }
            
            cvar=c;
            while(cvar<matrix[0].size())
            {
               matrix[r][cvar]=0;
                cvar++;
            }
            
            
            
            
        }
    }
};