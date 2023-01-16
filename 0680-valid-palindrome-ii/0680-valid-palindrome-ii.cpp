class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        int cnt1=0;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                i++;
                cnt1++;
            }
            else
            {
                i++;
                j--;
            }
        }
        i=0,j=n-1;
        int cnt2=0;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                j--;
                cnt2++;
            }
            else
            {
                i++;
                j--;
            }
        }
        if(cnt1>1 && cnt2>1) return false;
        return true;
    }
};