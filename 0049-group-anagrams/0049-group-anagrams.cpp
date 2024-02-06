class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> ans;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];;
            string t=s;
            sort(s.begin(),s.end());
            m[s].push_back(t);
        }
        
        for(auto it:m)
        {
            ans.push_back({it.second});
        }
        return ans;
    }
};