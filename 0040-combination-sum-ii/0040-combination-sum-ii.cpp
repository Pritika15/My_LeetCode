class Solution {
public:
void solve(int indx,vector<int>&v,set<vector<int>>&ans, vector<int> &arr, int n, int target)
{
	if(target==0)
	{
		ans.insert(v);
		return;
	}
	for(int i=indx;i<n;i++)
	{
		if(i>indx && arr[i]==arr[i-1]) continue;
		if(arr[i]>target) break;
		 v.push_back(arr[i]);
		solve(i+1,v,ans,arr,n,target-arr[i]);
		v.pop_back();
		
	}
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
    set<vector<int>>ans;
    vector<vector<int>>a;
	vector<int>v;
    int n=candidates.size();
	sort(candidates.begin(),candidates.end());
	solve(0,v,ans,candidates,n,target);
    for(auto itr:ans)
    {
        a.push_back(itr);
    }
	return a;
    }
};