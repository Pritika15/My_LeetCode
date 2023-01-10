class Solution {
public:
//     void helper(int index,vector<int>& candidates, int target,vector<int>&v,vector<vector<int>>&ans)
//     {
//         if(target==0) ans.push_back(v);
        
//         for(int i=index;i<candidates.size();i++)
//         {
//             if(i!=index && candidates[i]==candidates[i-1] ) continue;
//             if(candidates[i]>target) break;
//             v.push_back(candidates[i]);
//             helper(index+1,candidates,target-candidates[i],v,ans);
//             v.pop_back();
//         }
//     }
    
    void f(vector<int> &arr, int target, int idx, vector<int>ds, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
        }
        for(int i = idx; i<arr.size(); i++){
            if(i!= idx and arr[i]==arr[i-1])    continue;
            if(arr[i]>target)   break;
            ds.push_back(arr[i]);
            f(arr, target-arr[i], i+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>> ans;
//         vector<int>v;
        
//         helper(0,candidates,target,v,ans);
//         return ans;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int > ds;
        f(candidates,target, 0, ds, ans);
        return ans;
    }
};