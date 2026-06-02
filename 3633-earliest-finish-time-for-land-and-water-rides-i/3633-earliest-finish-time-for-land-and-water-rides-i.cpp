class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            int curr = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {

                int a = max(curr,waterStartTime[j])+waterDuration[j];
                ans = min(ans, a);
            }
        }

        for (int i = 0; i < m; i++) {
            int curr = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n; j++) {

                int a = max(curr, landStartTime[j])+landDuration[j];
                ans = min(ans, a);

            }
        }

        return ans;
    }
};