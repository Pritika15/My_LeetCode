class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>m(26);
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            for(int j=0;j<temp.length();j++)
            {
                m[temp[j]-'a']++;
            }
        }
        
        for(auto itr:m)
        {
            if(itr%words.size()!=0) return false;
        }
        return true;
    }
};