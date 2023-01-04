class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(int i=0;i<tasks.size();i++)
            m[tasks[i]]++;
        int ans=0;
        for(auto x:m)
        {
            if(x.second== 1) 
            {
                return -1;
                break;
            }
            else
            {
                ans+=ceil((float) x.second/3);
            }
            
        }
        return ans;
    }
};