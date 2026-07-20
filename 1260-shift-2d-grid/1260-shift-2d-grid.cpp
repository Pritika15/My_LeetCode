class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        int flat_index,new_flat_index = 0;
       
       for(int i =0;i<m;i++)
       {
        for(int j =0 ;j<n;j++)
        {
           flat_index = i * n + j;
           new_flat_index = (flat_index + k) % (m * n);
           result[new_flat_index/n][new_flat_index%n] = grid[i][j];

        }
       }

       return result;

    }
};