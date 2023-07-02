class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>m;
        for(int i=0;i<wordList.size();i++)
        {
            m[wordList[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==endWord) return level;
            for(int i=0;i<curr.length();i++)
            {
                string temp=curr;
                for(char ch='a';ch<='z';ch++)
                {
                   temp[i]=ch;
                    if(m.find(temp)!=m.end())
                    {
                        q.push({temp,level+1});
                        m.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};