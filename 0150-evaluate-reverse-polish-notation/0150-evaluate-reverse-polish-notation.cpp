class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/" )
            {
//                 operator ---> pop out the last 2 eles : apply that operator and push back the result;
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                
                if(tokens[i][0]=='+') s.push(op1+op2);
                else if(tokens[i][0]=='-') s.push(op1-op2);
                else if(tokens[i][0]=='*') s.push(op1*op2);
                else s.push(op1/op2);
//                     4+5===== 45+
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};