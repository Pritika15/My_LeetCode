//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        map<string,int>m;
        for(int i=0;i<wordList.size();i++)
        {
            m[wordList[i]]++;
        }
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty())
        {
            string curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==targetWord) return level;
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends