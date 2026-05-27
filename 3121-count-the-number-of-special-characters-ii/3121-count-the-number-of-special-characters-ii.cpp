class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<pair<int,int>>pos(26,{INT_MAX,INT_MIN});
        for(int i =0; i<word.length();i++)
        {
            if(word[i]>='a' && word[i]<='z')
            pos[word[i]-'a'].first=i;
            else
            if(pos[word[i]-'A'].second == INT_MIN)pos[word[i]-'A'].second = i;

        }

        for(auto ptr: pos)
        {
            if(ptr.second>ptr.first) count++;
        }

        return count;

    }
};