class DisJoint{
    public:
    vector<int>parent,size;
    
    DisJoint(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        size.resize(n),0;
    }
    
    int FindParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        
        return parent[node]=FindParent(parent[node]);
    }
    
    void UnionBySize(int u, int v)
    {
        int ulp_u=FindParent(u);
        int ulp_v=FindParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
         unordered_map<string,int>m;
        int n=accounts.size();
         DisJoint ds(n);
        for(int i=0;i<accounts.size();i++)
        {
           for(int j=1;j<accounts[i].size();j++)
           {
               string mail=accounts[i][j];
               
               if(m.find(mail)==m.end())
               {
                   m[mail]=i;
               }
               else
               {
                   ds.UnionBySize(i,m[mail]);
               }
           }
        }
        
        vector<string>MergedMail[n];
        for(auto it:m)
        {
            string s=it.first;
            int node=ds.FindParent(it.second);
            MergedMail[node].push_back(s);
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(MergedMail[i].size()==0) continue;
            
            sort(MergedMail[i].begin(),MergedMail[i].end());
            
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:MergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};