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
    int findHeight(TreeNode* root)
    {
        if(root==nullptr) return 0;

        int l = findHeight(root->left);
        int r = findHeight(root->right);

        if(l== -1 || r== -1) return -1;
        if(abs(l-r)>1) return -1;

        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        TreeNode* temp = root;
        int ans = findHeight(temp);
        if(ans> -1) return true;
        else return false;
        
    }
};