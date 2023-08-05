class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.length();
        int lt=0,rt=n-1;
        int ans=0;
        while(lt<rt)
        {
            int l=lt;
            int r=rt;
            while(s[l]!=s[r]) r--;
            
            if(l==r)
            {
                swap(s[r],s[r+1]);
                ans++;
                continue;
            }
            else
            {
                while(r<rt)
                {
                    swap(s[r],s[r+1]);
                    r++;
                    ans++;
                }
            }
            lt++;
            rt--;
        
        }
        return ans;
    }
};