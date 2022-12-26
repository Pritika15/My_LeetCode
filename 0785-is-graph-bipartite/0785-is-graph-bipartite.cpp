class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(color[i]) continue;
            
           
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto neighbour:graph[node])
                    {
                        if(color[neighbour]==0)
                        {
                            color[neighbour]=-color[node];
                            q.push(neighbour);
                        }
                        else if(color[neighbour]==color[node]) return false;
                    }
                }
            
            
        }
        return true;
    }
};