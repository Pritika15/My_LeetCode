class Solution {
public:
    
    int longestCycle(vector<int>& edges) {
        vector<bool>vis(edges.size(),false);
        vector<bool>extra(edges.size(),false);
        vector<int>dis(edges.size(),0);
        int ans= -1;
        int distance;
        for(int i=0;i<edges.size();i++)
        {
            if(vis[i]==0)
            dfs(i,edges,vis,extra,ans,0,dis);
        }
        return ans;
    }
    void dfs(int node, vector<int>&edges, vector<bool>&vis, vector<bool>&extra,int &ans,int distance,vector<int>&dis)
    {
        if(node!= -1)
        {
            if(!vis[node])
            {
                vis[node]=true;
                extra[node]=true;
                dis[node]=distance;
                dfs(edges[node],edges,vis,extra,ans,distance+1,dis);
                
            }
            else if(extra[node])
            {
                ans=max(ans,distance-dis[node]);
            }
            extra[node]=false;
            
            
        }
    }
};