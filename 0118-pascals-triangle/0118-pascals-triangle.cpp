class Solution {
public:
    vector<int>generateRow(int r)
    {
       vector<int>v;
        long long ans=1;
        v.push_back(1);
        for(int col=1;col<r;col++)
        {
            ans=ans*(r-col);
            ans=ans/col;
            v.push_back(ans);
        }
        return v;
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};