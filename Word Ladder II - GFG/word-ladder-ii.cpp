//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
         vector<vector<string>>ans;
         map<string,int>m;
         for(int i=0;i<wordList.size();i++)
         {
             m[wordList[i]]++;
         }
         queue<vector<string>>q;
         q.push({beginWord});
         int level=0;
         vector<string>v;
         v.push_back(beginWord);
         while(!q.empty())
         {
            
             vector<string>temp=q.front();
             q.pop();
             
             if(temp.size()>level)
             {
                 level++;
                 for(auto it:v)
                 {
                     m.erase(it);
                 }
             }
             int n=temp.size();
             string t=temp[n-1];
             if(t==endWord) ans.push_back(temp);
            
             for(int i=0;i<t.length();i++)
             {
                 string tt=t;
                 for(char ch='a';ch<='z';ch++)
                 {
                     tt[i]=ch;
                     if(m.find(tt)!=m.end())
                     {
                         temp.push_back(tt);
                         q.push(temp);
                         v.push_back(tt);
                         temp.pop_back();
                     }
                 }
             }
                
           
            
             
             
         }
         return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends