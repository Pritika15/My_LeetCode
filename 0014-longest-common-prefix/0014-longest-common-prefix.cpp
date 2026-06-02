class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if(n<=1) return strs[0];
        bool match = false;
        for(int i =0;i<strs[0].length();i++)
        {
            char a = strs[0][i];

            for(int j =1;j<n;j++)
            {
                if(strs[j][i]!=a)
                {
                    match = false;
                    break;
                }
                match = true;
                
            }
            if(!match) break;
            ans.push_back(strs[0][i]);
        }
        return ans;
        
    }
};