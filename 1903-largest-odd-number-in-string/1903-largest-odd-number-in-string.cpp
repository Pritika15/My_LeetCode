class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        bool odd = false;

        for(int i =n-1;i>=0;i--)
        {
            if((int)num[i]%2!=0)
            {num = num.substr(0,i+1);
            odd= true;
            break;} 
        }
        return odd==false ? "": num;
        
    }
};