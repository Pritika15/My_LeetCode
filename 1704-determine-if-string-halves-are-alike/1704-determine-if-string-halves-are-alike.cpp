#include<bits/stdc++.h> 
class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char>vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        // unordered_map<char,int>m1,m2;
       transform(s.begin(), s.end(), s.begin(), ::tolower);
        int cnt1=0,cnt2=0;
        for(int i=0;i<(s.length())/2;i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                cnt1++;
            }
        }
        for(int i=(s.length())/2;i<s.length();i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                cnt2++;
            }
        }
        cout<<cnt1<<" "<<cnt2;
       if(cnt1!=cnt2) return false;
     

        return true;
        
    }
};