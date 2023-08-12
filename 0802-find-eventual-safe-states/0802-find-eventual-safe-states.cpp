class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis, vector<int>&ans,vector<vector<int>>& graph)
    {
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto itr:graph[node])
        {
            if(!vis[itr])
            {
                if(dfs(itr,vis,pathVis,ans,graph)==true) return true;
            }
            else if(pathVis[itr]==1) return true;
        }
        ans.push_back(node);
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<int> ans;
        int n=graph.size();
        vector<int>vis(n,0),pathVis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathVis,ans,graph);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    
    }
};