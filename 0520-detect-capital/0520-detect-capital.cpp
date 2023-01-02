class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(int(word[i])>=65 && int(word[i])<=90)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        if(count(v.begin(),v.end(),1)==v.size()) return true;
         if(count(v.begin(),v.end(),0)==v.size()) return true;
        if(v[0]==1 && count(v.begin(),v.end(),0)==v.size()-1) return true;
        return false;
    }
};