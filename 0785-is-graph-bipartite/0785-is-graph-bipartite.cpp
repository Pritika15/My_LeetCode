class Solution {
public:
    bool dfs(int indx,vector<vector<int>>& graph,vector<int>&color,bool col)
    {
        color[indx]=col;
        for(auto itr:graph[indx])
        {
            if(color[itr]== -1)
            {
               // col=!col;
                if(dfs(itr,graph,color,!col)==false) return false;
            }
            else
            {
                if(color[itr]==col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //using DFS
       int n=graph.size();
        vector<int>color(n,-1);
        bool col=0;
        for(int i=0;i<n;i++)
        {
            if(color[i]== -1)
            {
                if(dfs(i,graph,color,col)==false) return false;
            }
            
        }
        return true;
    }
};