class Solution {
public:
    string reverseWords(string s) {
        stack<string>str;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            string temp;
            if(s[i]== ' ')
            {
                continue;
            }
            while(i<n && s[i]!= ' ')
            {
                temp+=s[i];
                i++;
            }
            str.push(temp);
        }
        
        string ans;
        while(!str.empty())
        {
            ans+=str.top();
            str.pop();
            if(!str.empty())
                ans+=" ";
        }
        return ans;
    }
};