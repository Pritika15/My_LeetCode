/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        TreeNode* temp = root;
        queue<pair<TreeNode* ,pair<int,int>>>q;
        q.push({temp,{0,0}});
        map<int, map<int, multiset<int>>>m;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for(int i =0;i<size;i++)
            {
                TreeNode* t = q.front().first;
                int vertical = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                m[vertical][level].insert(t->val);
                if(t->left) q.push({t->left,{vertical-1,level+1}});
                if(t->right) q.push({t->right,{vertical+1,level+1}});
            }
        }
        for(auto ele:m)
        {
            vector<int> col;
            for (auto q : ele.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};