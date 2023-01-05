class Solution {
public:
    int helper(int n)
    {
       int newnum=0;
        while(n>0)
        {
            newnum+=(n%10)*(n%10);
            n=n/10;
        }
        return newnum;
    }
    bool isHappy(int n) {
        while(1)
        {
            if(n==89) return false;
            else if(n==1) return true;
           n= helper(n);
        }
    }
};