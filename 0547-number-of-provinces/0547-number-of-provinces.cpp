class Solution {
public:
    void dfs(int node,vector<int>adjList[],vector<int>&vis)
    {
        
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dfs(it,adjList,vis);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int count=0;
        vector<int>adjList[v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 &&i!=j)
                {
                   adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
       
        vector<int>vis(v+1,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                // ans.push_back(i);
                // vis[i]=1;
                dfs(i,adjList,vis);
                count++;
            }
            
        }
        return count;
    }
};