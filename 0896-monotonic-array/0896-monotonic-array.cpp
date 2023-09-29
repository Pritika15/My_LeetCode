class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>A=nums;
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};