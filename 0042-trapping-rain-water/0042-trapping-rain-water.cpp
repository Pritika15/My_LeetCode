#include<bits/stdc++.h>
class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
    vector<int>prefix;
    vector<int>suffix;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,height[i]);
        prefix.push_back(maxi);

    }
   
    maxi=0;
    for(int i=n-1;i>=0;i--)
    {
        maxi=max(maxi,height[i]);
        suffix.push_back(maxi);
    }
    reverse(suffix.begin(),suffix.end());
    // for(auto itr:suffix)
    // cout<<itr<<" ";
    long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(min(prefix[i],suffix[i]))-height[i];
    }
    return ans;
    }
};