class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] != '0') return false; // Base check: if destination is '1', impossible

        // dp[i] will be true if we can reach index i from index 0
        vector<bool> dp(n, false);
        dp[0] = true; // We start at index 0

        int activeJumps = 0; // Tracks how many reachable '0' positions can jump to current i

        for (int i = 1; i < n; i++) {
            // 1. Slide Window Right: Add new valid starting point into our reach
            if (i >= minJump && dp[i - minJump]) {
                activeJumps++;
            }

            // 2. Slide Window Left: Remove starting points that are now too far away
            if (i > maxJump && dp[i - maxJump - 1]) {
                activeJumps--;
            }

            // 3. If we have active available jumps and current spot is '0', it's reachable!
            if (activeJumps > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};