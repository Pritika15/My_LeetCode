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
    int solve(TreeNode* root,int cnt)
    {
        if(!root) return 0;
        cnt^=1<<(root->val-1);
        int res=solve(root->left,cnt)+solve(root->right,cnt);
        if(root->left==root->right && (cnt & (cnt-1))==0) res++;
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root,0);
    }
};