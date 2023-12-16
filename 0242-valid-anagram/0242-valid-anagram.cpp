class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        for(int i=0;i<s.length();i++) m1[s[i]]++;
        for(int j=0;j<t.length();j++) m2[t[j]]++;
        
        vector<pair<char,int>>v1;
        vector<pair<char,int>>v2;
        for(auto itr:m1)
        {
            v1.push_back({itr.first,itr.second});
        }
        for(auto itr1:m2)
        {
            v2.push_back({itr1.first,itr1.second});
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++)
        {
            char ch1=v1[i].first;
            int num1=v1[i].second;
            char ch2=v2[i].first;
            int num2=v2[i].second;
            if(ch1!=ch2)return false;
            if(num1!=num2)return false;
        }
        return true;
        
    }
};