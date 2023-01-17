class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1=0;
        int flip=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                cnt1++;
                
            }
            else
            {
                flip++;
            }
            flip=min(flip,cnt1);
        }
        return flip;
    }
};