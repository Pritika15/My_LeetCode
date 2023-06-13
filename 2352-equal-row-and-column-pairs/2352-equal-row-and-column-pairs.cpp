class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        map<vector<int>,int>m;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(grid[i][j]);
                m[temp]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int>t;
            for(int j=0;j<n;j++)
            {
                t.push_back(grid[j][i]);
            }
            if(m.find(t) != m.end())
            {
                cnt+=m[t];
            }
        }
        return cnt;
    }
};