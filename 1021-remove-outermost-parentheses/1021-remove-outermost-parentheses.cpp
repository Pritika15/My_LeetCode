class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n = s.length();
        vector<pair<int,int>>v;
        st.push(s[0]);
        int start = 0;
        string ans ="";

        for(int i =1;i<n;i++)
        {
            if(s[i] == ')')
            {
                st.pop();
                if(st.empty() && i<n)
                {
                    v.push_back({start,i});
                    start = i+1;

                } 
            }
            else{st.push(s[i]);}
        }

        for( auto ptr: v)
        {
            s[ptr.first] = 'a';
            s[ptr.second] = 'a'; 
        }

        for(int i =0;i<n;i++)
        {
            if(s[i]!='a') ans.push_back(s[i]);
        }
        return ans;
    }
};