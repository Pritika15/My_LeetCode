class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int  n1=word1.length();
        int n2=word2.length();
        string ans="";
        if(n1==n2)
        {
            for(int i=0;i<n1;i++)
            {
                ans=ans+word1[i]+word2[i];
            }
        }
        else if(n1>n2)
        {
            int i;
            for(i=0;i<n2;i++)
            {
                ans=ans+word1[i]+word2[i];
            }
            for(i;i<n1;i++)
                ans+=word1[i];
            
        }
        else
        {
            int i;
            for(i=0;i<n1;i++)
            {
                ans=ans+word1[i]+word2[i];
            }
            for(i;i<n2;i++)
                ans+=word2[i];
        }
        return ans;
    }
};