//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>AdjList[K];
        string ans;
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    AdjList[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int>ReverseAdj[K];
        vector<int>Indegree(K,0);
        for(int i=0;i<K;i++)
        {
            for(auto ptr:AdjList[i])
            {
                ReverseAdj[ptr].push_back(i);
                Indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<K;i++)
        {
            if(Indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x+'a');
            for(auto m:ReverseAdj[x])
            {
                Indegree[m]--;
                if(Indegree[m]==0) q.push(m);
            }
        }
        // for(auto x:ans)
        // cout<<x;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends