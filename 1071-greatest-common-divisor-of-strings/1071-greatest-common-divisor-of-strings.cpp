class Solution {
public:
    string helper(string s1, string s2)
    {
        int n1=s1.length();
        int n2=s2.length();
        if(n2>n1)
        {
            return helper(s2,s1);
        }
        else if(s1.find(s2)!=0)
        {
            return "";
        }
        else if(s2=="")
        {
            return s1;
        }
        else
        {
            return helper(s1.substr(n2),s2);
        }
    }
    string gcdOfStrings(string str1, string str2) {
        return helper(str1,str2);
    }
};