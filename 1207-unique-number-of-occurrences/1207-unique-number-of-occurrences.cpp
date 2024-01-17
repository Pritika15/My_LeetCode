class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it:arr)
        {
            m[it]++;
        }
        set<int>s;
        for(auto it:m)
        {
            if(s.find(it.second)!=s.end()) return false;
            s.insert(it.second);
        }
        return true;
    }
};