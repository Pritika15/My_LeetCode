#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
       vector <string> t=tokens;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+" or t[i]=="-" or t[i]=="*" or t[i]=="/"){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                switch(t[i][0]){
                    case '+':
                        s.push(op1+op2);
                        break;
                    case '-':
                        s.push(op1-op2);
                        break;
                    case '*':
                        s.push(op1*op2);
                        break;
                    case '/':
                        s.push(op1/op2);
                        break;
                }
            }
            else{
                s.push(stoi(t[i]));
            }
        }
        return s.top();
    }
};