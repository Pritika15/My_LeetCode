class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>m1;
        int maxLen = 0, maxFreq=0, start=0;

        for(int end = 0;end<n;end++)
        {
            m1[s[end]]++;
            maxFreq = max(maxFreq,m1[s[end]]);

            while((end-start+1)-maxFreq > k)
            {
                m1[s[start]]--;
                start++;
            }
            maxLen = max(maxLen, end-start+1);

        }
        return maxLen;
    }
};