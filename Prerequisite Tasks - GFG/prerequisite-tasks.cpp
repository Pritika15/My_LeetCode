//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>AdjList[N];
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        int u=prerequisites[i].first;
	        int v=prerequisites[i].second;
	        AdjList[u].push_back(v);
	    }
	    
	    vector<int>Indeg(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:AdjList[i])
	        {
	            Indeg[it]++;
	        }
	        
	    }
	    
	    stack<int>st;
	    for(int i=0;i<N;i++)
	    {
	        if(Indeg[i]==0) st.push(i);
	    }
	    vector<int>v;
	    while(!st.empty())
	    {
	        int node=st.top();
	        st.pop();
	        v.push_back(node);
	        for(auto it:AdjList[node])
	        {
	            Indeg[it]--;
	            if(Indeg[it]==0) st.push(it);
	        }
	    }
	    
	    if(v.size()==N) return true;
	    return false;
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
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends