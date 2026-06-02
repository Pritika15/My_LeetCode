class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        int n = s.length();
        string ans = "";

        for(int i =0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(depth>0) ans.push_back(s[i]);
                depth++;

            } 
            else
            {
                depth--; 
                if(depth>0) ans.push_back(s[i]);

            } 
            
        }
        return ans;
        
    }
};