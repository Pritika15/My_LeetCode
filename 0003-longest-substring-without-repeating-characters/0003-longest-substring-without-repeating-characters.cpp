class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.length()<=0) return 0;
    int h=0,t=0;
    map<char,int>m;
    int cnt=0;
    int maxi=INT_MIN;
    while(h<s.length())
    {
        if(m.find(s[h])!=m.end())
        {
            while(s[t]!=s[h])
            {
                m.erase(s[t]);
                t++;
                cnt--;
            }
            if(s[t]==s[h])
            {
                t++;
            }
            // m.clear();
            // cnt=0;
            // h=h-1;
            // h=t;
        }
        else{
            m.insert({s[h],1});
           
            cnt++;
        }
        
        maxi=max(maxi,cnt);
         h++;
    }
    return maxi;
    }
};