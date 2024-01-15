class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int,int>m;
        for(int i=0;i<matches.size();i++)
        {
            vector<int>v=matches[i];
            m[v[1]]++;
        }
        set<int>s;
        for(int i=0;i<matches.size();i++)
        {
            vector<int>v=matches[i];
            s.insert(v[0]);
        }
        
        vector<int>v1;
        for(auto it:s)
        {
            if(m.find(it)==m.end())
            {
                v1.push_back(it);
            }
        }
        
        vector<int>v2;
        for(auto it:m)
        {
            if(it.second==1)
            {
                v2.push_back(it.first);
            }
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        ans.push_back(v1);
        ans.push_back(v2);
        
        return ans;
        
            
    }
};