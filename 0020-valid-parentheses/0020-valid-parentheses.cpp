class Solution {
public:
    bool isValid(string s) {
         stack<char>s1;
        bool ans = true;
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.empty()) return false;
                char top = s1.top();
                if((top =='(' && s[i]!=')' )|| (top=='[' && s[i]!=']') || (top=='{' && s[i]!='}') ) return false;
                s1.pop();
            }
        }
        if(!s1.empty()) return false;
        return ans;
    }
};