class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> m;
        int n = s.length();
        
        // Store the positions of each character
        for (int i = 0; i < n; i++) {
            m[s[i]].push_back(i);
        }

        int ans = -1;
        
        // Iterate over the positions and calculate the length of substrings
        for (const auto& entry : m) {
            const vector<int>& positions = entry.second;
            int numPositions = positions.size();

            if (numPositions >= 2) {
                int length = positions[numPositions - 1] - positions[0] - 1;
                ans = max(ans, length);
            }
        }

        return ans;
    }
};