class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        char temp;
        int n=columnNumber;
        while(n)
        {
            n=n-1;
            temp='A'+(n%26);
            ans=temp+ans;
            n=n/26;
        }
        return ans;
        
    }
};