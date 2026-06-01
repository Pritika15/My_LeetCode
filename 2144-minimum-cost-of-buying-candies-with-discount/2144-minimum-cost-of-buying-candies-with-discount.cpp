class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0;
        sort(cost.begin(), cost.end());
        int n = cost.size();
        
        for (int i = n - 1; i >= 0; i -= 3) {
            // Always add the current most expensive item
            sum += cost[i];
            
            // If there is a second most expensive item available, add it too
            if (i - 1 >= 0) {
                sum += cost[i - 1];
            }
            // The third item (at i - 2) is free, so we skip it!
        }
        
        return sum;
    }
};