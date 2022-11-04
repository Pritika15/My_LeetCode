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
    int sum=0;
    int solve(TreeNode* root, bool flag)
    {
        
        if(root==NULL) return sum;
        solve(root->left,true);
        solve(root->right,false);
        if(root->left==NULL && root->right==NULL && flag==true)
            sum+=root->val;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag=false;
         solve(root,flag);
        return sum;
        
    }
};