class Solution {
public:
    bool dfs(int i, vector<int>adjList[], vector<int>&vis,vector<int>&pathVis, vector<int>&check,vector<vector<int>>& graph )
    {
        vis[i]=1;
        pathVis[i]=1;
        check[i]=0;
        for(auto adjNode:graph[i])
        {
            if(!vis[adjNode])
            {
               if( dfs(adjNode,adjList,vis,pathVis,check,graph)==true) 
               {
                   check[i]=0;
                   return true;
               }
            }
            else if(pathVis[adjNode]) 
            {check[i]=0;
                return true;}
        }
        check[i]=1;
        pathVis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>adjList[n];
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>check(n,1);
        vector<int>Safenodes;
       
       
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adjList,vis,pathVis,check,graph);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1) Safenodes.push_back(i);
        }
        return Safenodes;
    }
};