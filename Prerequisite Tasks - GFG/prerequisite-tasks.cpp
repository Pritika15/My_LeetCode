//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	     
        vector<int>vis(N,0);
        
        vector<int>AdjList[N];
        //BFS-->Kahns
        queue<int>q;
        for(int i=0;i<prerequisites.size();i++)
        {
            int x=prerequisites[i].first;
            int y=prerequisites[i].second;
            AdjList[x].push_back(y);
        }
        
        vector<int>Indegree(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto itr:AdjList[i])
            {
                Indegree[itr]++;
            }
        }
        
        for(int i=0;i<Indegree.size();i++)
        {
            if(Indegree[i]==0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            int xx=q.front();
            q.pop();
            cnt++;
            for(auto it:AdjList[xx])
            {
                Indegree[it]--;
                if(Indegree[it]==0) q.push(it);
            }
        }
        if(cnt!=N){
            return  false;}
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends