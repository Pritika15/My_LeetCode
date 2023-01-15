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
    void helper(TreeNode* root, vector<int>&v,vector<vector<int>>&ans,int targetSum)
    {
        
       if(root==NULL) return;
         v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
            ans.push_back(v);
           
        helper(root->left,v,ans,targetSum-root->val);
        helper(root->right,v,ans,targetSum-root->val);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,v,ans,targetSum);
        return ans;
    }
};