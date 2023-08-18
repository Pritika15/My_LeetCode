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
    bool Check(TreeNode* root, long mini, long maxi)
    {
        if(!root) return true;
        if(root->val >maxi || root->val<mini || root->val==mini || root->val==maxi) return false;
        
        return Check(root->left,mini,root->val) && Check(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return Check(root,LONG_MIN,LONG_MAX);
    }
};