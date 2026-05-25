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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root)solve(root,ans);
        return ans;
    }
    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->val);
            return;

        } 
        if(root->left)  solve(root->left,ans);
        if(root->right) solve(root->right,ans);
        ans.push_back(root->val);
    }
};