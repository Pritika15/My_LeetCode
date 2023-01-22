class Solution {
public:
    bool isPalin(string t, int start, int end)
    {
        while(start<=end)
        {
            if(t[start]!=t[end]) return false;
            
            start++;
            end--;
        }
        return true;
    }
    void helper(int index,string s, vector<vector<string>>&ans,vector<string>&temp)
    {
        if(index==s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(isPalin(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                helper(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
        vector<string>temp;
        helper(0,s,ans,temp);
        return ans;
    }
};