class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char>s;
        //s.push(num[0]);
        if(k>=num.length()) return "0";
        for(auto c:num)
        {
            while(!s.empty() && k>0 && s.top()>c)
            {
                s.pop();
                k--;
            }
            if(c=='0' && s.empty()) continue;
            s.push(c);
        }
        while(!s.empty() && k>0)
        {
            s.pop();
            k--;
        }
            
        if(s.size()==0) return "0";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};