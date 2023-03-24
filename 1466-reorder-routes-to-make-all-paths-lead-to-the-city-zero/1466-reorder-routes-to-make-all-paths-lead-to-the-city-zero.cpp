class Solution {
public:
    vector<int>adjList[50005];
    bool vis[50005];
    set<pair<int,int>>s;
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(vis,false,sizeof(vis));
        for(int i=0;i<connections.size();i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
            s.insert({connections[i][0],connections[i][1]});
        }
        queue<int>q;
        q.push(0);
        int total=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            if(!vis[k])
            {
                vis[k]=1;
                for(int i=0;i<adjList[k].size();i++)
                {
                    q.push(adjList[k][i]);
                    if(!vis[adjList[k][i]] && s.count({k,adjList[k][i]}))
                        total++;
                }
            }
                
        }
        return total;
    }
};