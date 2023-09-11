class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int>gz=groupSizes;
         vector<vector<int>> res, groups(gz.size() + 1);
  for (auto i = 0; i < gz.size(); ++i) {
    groups[gz[i]].push_back(i);
    if (groups[gz[i]].size() == gz[i]) {
      res.push_back({});
      swap(res.back(), groups[gz[i]]);
    }
  }
  return res;
    }
};