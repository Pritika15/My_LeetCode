class Solution {
public:
    string minWindow(string s, string t) {
//         step1
        unordered_map<char,int>m;
        for(auto ch:t) m[ch]++;
//         variables creatation : ranges for the window and lengths corresponding to the substrs possible
        int cnt=0,mini_len=1e9,mini_start=0,low=0;
        
//         work with the str s
        for(int h=0;h<s.length();h++)
        {
            if(m[s[h]]>0) cnt++;
            m[s[h]]--;
            
            if(cnt==t.size())
            {
                while(low<=h && m[s[low]]<0)
                {
                    m[s[low]]++;
                    low++;
                }
                
                if(mini_len>(h-low+1))
                {
                    mini_len=(h-low+1);
                    mini_start=low;
                }
            }
        }
        if(mini_len==1e9) return "";
        return s.substr(mini_start,mini_len);
        
    }
};