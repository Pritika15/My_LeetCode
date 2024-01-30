class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
         for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                // switch(t[i][0]){
                //     case '+':
                //         s.push(op1+op2);
                //         break;
                //     case '-':
                //         s.push(op1-op2);
                //         break;
                //     case '*':
                //         s.push(op1*op2);
                //         break;
                //     case '/':
                //         s.push(op1/op2);
                //         break;
                if(tokens[i][0]=='+') s.push(op1+op2);
                else if(tokens[i][0]=='-') s.push(op1-op2);
                else if(tokens[i][0]=='*') s.push(op1*op2);
                else s.push(op1/op2);
                // }
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};