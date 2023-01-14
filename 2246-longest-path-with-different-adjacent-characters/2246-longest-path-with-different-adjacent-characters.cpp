class Solution {
public:
    vector<int>child[100001];
    int ans=1;
    int dfs(int curr_node,string &s)
    {
        if(child[curr_node].empty()) return 1;
        int mx1=0,mx2=0;
        for(auto x:child[curr_node])
        {
            int len=dfs(x,s);
            ans=max(len,ans);
            
            if(s[curr_node]==s[x]) continue;
            
            if(len>mx1)
            {
                mx2=mx1;
                mx1=len;
            }
            else
            {
                mx2=max(mx2,len);
            }
           
        }
         ans=max(ans,mx1+mx2+1);
            return 1+mx1;
    }
    int longestPath(vector<int>& parent, string s) {
        for(int i=1;i<parent.size();i++)
        {
            child[parent[i]].push_back(i);
        }
        
        
        dfs(0,s);
        return ans;
    }
};