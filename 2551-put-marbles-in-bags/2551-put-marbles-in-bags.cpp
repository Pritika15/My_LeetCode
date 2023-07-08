class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>Sum;
        int n=weights.size();
        for(int i=0;i<n-1;i++)
        {
            int s=weights[i]+weights[i+1];
            Sum.push_back(s);
        }
        sort(Sum.begin(),Sum.end());
        
        
        long long mini=0, maxi=0;
       
       for(int i=0;i<k-1;i++)
       {
           mini+=Sum[i];
           maxi+=Sum[n-2-i];
       }
        return maxi-mini;
    }
};