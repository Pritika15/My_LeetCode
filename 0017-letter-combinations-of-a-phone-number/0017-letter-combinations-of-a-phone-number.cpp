class Solution {
public:
    void solve(int indx,string digits,string output,vector<string>&ans,vector<string>pad)
    {
        if(indx>=digits.length())
        {
            ans.push_back(output);
            return;
            
        }
        int number=digits[indx]-'0';
        string value=pad[number];
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(indx+1,digits,output,ans,pad);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        string output;
        vector<string>pad={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,output,ans,pad);
        return ans;
    }
};