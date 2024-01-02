#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }

        std::vector<std::vector<int>> ans;
        while (!m.empty()) {
            std::vector<int> v;
            auto it = m.begin();
            while (it != m.end()) {
                v.push_back(it->first);
                if (--(it->second) == 0) {
                    it = m.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};
