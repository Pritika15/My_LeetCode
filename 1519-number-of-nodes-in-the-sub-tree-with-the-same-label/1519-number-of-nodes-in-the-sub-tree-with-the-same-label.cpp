class Solution {
public:
//     vector<vector<int>>adjList;
//      vector<int>v;
//     vector<int> dfs(int node,int p,string labels)
//     {
//         vector<int>count(26,0);
//         for(auto i:adjList[node])
//         {
//             if(i!=p)
//             {
//                 auto temp=dfs(i,node,labels);
//                 for(int i=0;i<26;i++)
//                     count[i]+=temp[i];
//             }
//         }
//         int ch=labels[node]-'a';
//         count[ch]++;
//         v[node]=count[ch];
//         return count;
       
//     }
//     vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//         adjList.resize(n);
//         // for(int i=0;i<edges.size();i++)
//         // {
//         //     adjList[edges[i][0]].push_back(edges[i][1]);
//         //     adjList[edges[i][1]].push_back(edges[i][0]);
//         // }
//          for(auto x:edges){
//             adjList[x[0]].push_back(x[1]);
//             adjList[x[1]].push_back(x[0]);
//         }
//        v.resize(n,1);
//         //vector<int>vis(n,0);
//         dfs(0,-1,labels);
        
//         return v;
//     }
    
    vector<vector<int>>adjlist;
     vector<int>ans;

    vector<int>  dfs(string &labels,int currentNode,int parent){
        // to store the count vector at each node
        vector<int>count(26,0);
        for(auto x:adjlist[currentNode]){
            // check only for children.
            if(x != parent){
                // it will return count vector for childern.
                  auto temp = dfs(labels,x,currentNode);
                // add temp freq to count freq .
                for(int i=0;i<26;i++){
                    count[i]+=temp[i];
                }
            }
         }
        //  cal for current node also and add it to the count vector
        int ch = labels[currentNode]-'a'; // for b i.e index ch = 1;
        count[ch]++;
        // store for the currentNode in ans.
        ans[currentNode] = count[ch];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
   adjlist.resize(n);
         ans.resize(n,1);
        for(auto x:edges){
            adjlist[x[0]].push_back(x[1]);
            adjlist[x[1]].push_back(x[0]);
        }
        // current node =0 , parent node =-1,distance or level from root.
        dfs(labels,0,-1);
        return ans;
    }
};