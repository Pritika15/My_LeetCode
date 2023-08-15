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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int cnt=1;
            for(int i=0;i<size;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if(cnt>0) ans.push_back(n->val);
                if(n->right) q.push(n->right);
                if(n->left) q.push(n->left);
                cnt--;
            }
        }
        return ans;
    }
};