class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        vector<int>v=machines;
        int sum = 0, n = v.size();
        for(auto &i: v)sum += i;
        if(sum%n)return -1;
        sum /= n;
        int k = 0;
        int ans = 0;
        for(auto &i: v){
            k += i-sum;
            ans = max({(i-sum),ans,abs(k)});
        }
        return ans;
    }
};