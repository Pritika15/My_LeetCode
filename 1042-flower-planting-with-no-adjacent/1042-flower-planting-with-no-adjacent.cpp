class Solution {
public:
    bool isPossible(int node,vector<int>&colors,int col,vector<int>adjList[])
    {
        for(auto x:adjList[node])
        {
            if(colors[x]==col) return false;
        }
        return true;
    }
    bool helper(int node,vector<int>adjList[],int n,vector<int>&colors)
    {
        if(node==n)
        {
            return true;
        }
        for(int col=1;col<=4;col++)
        {
            if(isPossible(node,colors,col,adjList))
            {
                colors[node]=col;
                if(helper(node+1,adjList,n,colors)==true)
                    return true;
                colors[node]=0;
            }
        }
        return false;
            
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int>adjList[10001];
        vector<int>colors(n,0);
        for(int i=0;i<paths.size();i++)
        {
            adjList[paths[i][0]-1].push_back(paths[i][1]-1);
            adjList[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        // for(int i=0;i<10001;i++)
        // {
        //     for(auto x:adjList[i])
        //     {
        //         cout<<i<<" "<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            if(colors[i]==0)
            {
                if(helper(i,adjList,n,colors)==true)
                    break;
            }
            
        }
        
        return colors;
        
    }
};