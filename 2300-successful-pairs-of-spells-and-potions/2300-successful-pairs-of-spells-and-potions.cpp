class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // int n=spells.size();
        // int m=potions.size();
       
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int it:spells)
        {
            long need=(success+it-1)/it;
            auto indx=lower_bound(potions.begin(),potions.end(),need);
            ans.push_back(potions.end()-indx);
        }
        return ans;
    }
};