class Solution {
public:
    int timer=1;
    void dfs(int node, int parent,vector<int>&vis,int time[], int minTime[], vector<vector<int>>&ans,vector<int>AdjList[])
    {
        vis[node]=1;
        time[node]=minTime[node]=timer;
        timer++;
        for(auto it:AdjList[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,vis,time,minTime,ans,AdjList);
                minTime[node]=min(minTime[it],minTime[node]);
                
                if(minTime[it]>time[node]) ans.push_back({it,node});
            }
            else
            {
                 minTime[node]=min(minTime[it],minTime[node]);
                
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<int>AdjList[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        int time[n],minTime[n];
        
        dfs(0,-1,vis,time,minTime,ans,AdjList);
        return ans;
    }
};