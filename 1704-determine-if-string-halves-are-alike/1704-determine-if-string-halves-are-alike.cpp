class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        set<char>vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        
        int cnt1=0,cnt2=0;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(int i=0;i<n/2;i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                cnt1++;
            }
        }
        
         for(int i=n/2;i<n;i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                cnt2++;
            }
        }
        
        if(cnt1!=cnt2) return false;
        
        return true;
    }
};