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
   
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MAX,LONG_MIN);
    }
     bool helper(TreeNode* root, long maxVal, long minVal)
    {
        if(root==NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return helper(root->left,root->val,minVal)&& helper(root->right,maxVal,root->val);
    }
    
};