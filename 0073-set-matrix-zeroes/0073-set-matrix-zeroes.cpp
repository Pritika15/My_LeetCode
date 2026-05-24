class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> indices;
        for(int i =0;i<matrix.size();i++)
        {
            for(int j = 0 ;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0) indices.push_back({i,j});
            }
        }

        for(int i =0;i<indices.size();i++)
        {
            int row = indices[i].first;
            int col = indices[i].second;
            for(int j =0;j<matrix[0].size();j++)
            {
                matrix[row][j] = 0;
            }
            for(int k = 0;k<matrix.size();k++)
            {
                matrix[k][col]=0;
            }
            
        }
    }
};