class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans;
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            string temp="";
            while(!isspace(s[i]) && i<n)
            {
                temp.push_back(s[i]);
                i++;
            }
            if(!temp.empty()) v.push_back(temp);
        }
        
        for(int i=v.size()-1;i>=0;i--)
        {
            ans.append(v[i]);
            if(i>0) ans.append(" ");
        }
        return ans;
    }
};