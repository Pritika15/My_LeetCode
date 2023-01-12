class Solution {
public:
    vector<bool>apple;
    vector<int>adjList[100005];
    pair<int,int>dfs(int node, int p)
    {
        pair<int,int>v={0,apple[node]};
        for(auto i: adjList[node])
        {
            if(i!=p)
            {
               auto x=dfs(i,node);
                v.first+=(2+x.first)*x.second;
                v.second|=x.second;
            }
        }
        return v;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
//         int m=edges[0].size();
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 adjList[i].push_back(j);
//                 adjList[j].push_back(i);
//             }
//         }
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        apple=hasApple;
        return dfs(0,0).first;
    }
};