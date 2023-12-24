class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' && flag) return false;
            if(s[i]=='b')
                flag=true;
            
        }
        return true;
    }
};