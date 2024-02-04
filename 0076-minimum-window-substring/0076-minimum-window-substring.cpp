class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(auto it:t) m[it]++;
//         current window size
        int cnt=0,low=0,min_len=1e9,min_start=0;
        
//         iterate over the str s
        
        for(int h=0;h<s.length();h++)
        {
//             if the current char i'm standing on is a part of str t
            if(m[s[h]]>0) cnt++;
//             reduce the cnt for this char : included it to the window
            m[s[h]]--;
//             if all the valid chars have been touched(is the curr windpow having all the chars of str t)
            if(cnt==t.size())
            {
                while(low<h && m[s[low]] <0)
                {
                    m[s[low]]++;
                    low++;
                }
                
//                 update the substring 
                if(min_len> (h-low+1))
                {
                    min_start=low;
                    min_len=h-low+1;
                }
            }
        }
        
        if(min_len==1e9) return "";
        
        return s.substr(min_start,min_len);
    }
};