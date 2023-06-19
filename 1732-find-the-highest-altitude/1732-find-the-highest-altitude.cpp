class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
       // vector<int>v(n+1,0);
        int maxi=INT_MIN;
        int lastNum=0;
        //int j=1;
        for(int i=0;i<n;i++)
        {
            //v[j]=v[j-1]+gain[i];
            
            maxi=max(maxi,lastNum+gain[i]);
            lastNum+=gain[i];
            //j++;
        }
        //sort(v.begin(),v.end(),greater<int>());
        // for(int i=0;i<n+1;i++)
        //     cout<<v[i]<<" ";
        //return v[0];
        maxi=max(maxi,0);
        return maxi;
    }
};