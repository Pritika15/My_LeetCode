class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>lengths;
        int maxi=1;
        for(auto el:arr){
            maxi=max(maxi,lengths[el]=1+lengths[el-difference]);
        }
        return maxi;
        
    }
};