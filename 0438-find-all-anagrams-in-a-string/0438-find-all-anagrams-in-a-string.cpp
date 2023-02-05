class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>map;
        for(int i=0;i<p.length();i++)
        {
            map[p[i]]++;
        }
        int cnt=map.size();
        int k=p.length();
        int i=0,j=0;
        while(j<s.length())
        {
            if(map.find(s[j])!=map.end())
            {
                map[s[j]]--;
                if(map[s[j]]==0)
                    cnt--;
            }
            if(j-i+1 <k) j++;
            else if(j-i+1 ==k)
            {
                if(cnt==0)
                    ans.push_back(i);
                if(map.find(s[i])!=map.end())
                {
                    map[s[i]]++;
                    if(map[s[i]]==1) cnt++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};