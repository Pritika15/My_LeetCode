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
    int solve(TreeNode* root, int count ) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = solve(root->left, count) + solve(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root,0);
        
    }
};