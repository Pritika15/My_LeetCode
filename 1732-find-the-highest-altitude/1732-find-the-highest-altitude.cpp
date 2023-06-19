class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>v(n+1,0);
        int j=1;
        for(int i=0;i<n;i++)
        {
            v[j]=v[j-1]+gain[i];
            j++;
        }
        sort(v.begin(),v.end(),greater<int>());
        // for(int i=0;i<n+1;i++)
        //     cout<<v[i]<<" ";
        return v[0];
    }
};