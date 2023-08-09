class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mini= 1e9;
        for(int i=1;i<n;i++)
        {
            int diff=abs(arr[i]-arr[i-1]);
            if(diff<mini) mini=diff;
            
        }
        vector<int>temp;
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1])==mini)
            {
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};