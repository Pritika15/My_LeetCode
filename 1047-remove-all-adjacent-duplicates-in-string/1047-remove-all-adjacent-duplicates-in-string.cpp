class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        stack<char>ss;
        string ans;
        for(int i=0;i<n;i++)
        {
            ss.push(s[i]);
        }
        int i= -1;
        while(!ss.empty())
        {
            char temp=ss.top();
            if(ans.size()==0 || temp!=ans[i])
            {
                 ans.push_back(temp);
                i++;
            }
            else
            {
                ans.pop_back();
                i--;
            }
           
            ss.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};