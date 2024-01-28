class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        
//         Prefix Sum
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
//         Unoredered Map : Prefix Sum ---> frequency 
        unordered_map<int,int>mappy;
//         To explore all the possible combinations
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                mappy={{0,1}};
                int curr=0;
                
                for( int k=0;k<m;k++)
                {
                    curr+=matrix[k][j]-(i>0 ? matrix[k][i-1]:0);
                    res+=mappy.find(curr-target)!=mappy.end() ? mappy[curr-target]:0;
                    mappy[curr]++;
                }
            }
        }
        return res;
        
    }
};