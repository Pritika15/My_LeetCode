class Solution {
public:
    int firstUniqChar(string s) {
//     step 1
        vector<int>v(26,0);
        int ans= -1;
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        
//         traverse over the str s && use the vector of freq t get the first indeex
        for(int i=0;i<s.length();i++)
        {
            if(v[s[i]-'a']==1)
            {ans=i;
             break;
            }
        }
        
        return ans;
    }
};