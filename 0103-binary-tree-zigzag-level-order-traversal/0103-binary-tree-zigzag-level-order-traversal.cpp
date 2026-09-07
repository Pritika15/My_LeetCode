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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        TreeNode* temp = root;
        queue<TreeNode*>q;
        q.push(temp);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>v;
            for(int i =0;i<size;i++)
            {
                TreeNode* t = q.front();
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right)q.push(t->right);
                q.pop();
            }
            ans.push_back(v);
        }
        int cnt =0;
        for(int i =0;i<ans.size();i++)
        {
            
            if(cnt%2!=0) reverse(ans[i].begin(),ans[i].end());
            cnt++;

        }
        return ans;
    }
};