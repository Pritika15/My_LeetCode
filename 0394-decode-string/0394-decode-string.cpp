class Solution {
public:
    string decodeString(string s) {
         stack<string>charStack;
        stack<int>numStack;
        int currNum = 0;
        string currStr = "";

        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='[')
            {
                charStack.push(currStr);
                numStack.push(currNum);
                currNum = 0;
                currStr = "";
            }
            else if(s[i]==']')
            {
                int num = numStack.top();
                numStack.pop();
                string prevStr = charStack.top();
                charStack.pop();
                string temp = "";

                for(int i =0;i<num;i++)
                {
                    temp+=currStr;

                }

                currStr = prevStr+temp;

            }
            else if(isdigit(s[i]))
            {
                currNum = currNum*10+(s[i]-'0');
            }
            else{
                currStr+=s[i];
            }
        }
        return currStr;
        
    }
};