class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n = s.length();
        string temp = "";
        for(int i =0;i<n;i++)
        {
            if(s[i]!=' ' || (i==n-1 && s[i]!=' '))
            {
                temp.push_back(s[i]);
            }
            else
            {
                if(!temp.empty())st.push(temp);
                temp = "";
            }
        }
        if(!temp.empty())st.push(temp);
        temp = "";
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
            temp.push_back(' ');
        }
        temp.pop_back();
        return temp;
    }
};