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
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        
        
       
        int leftH=solve(root->left);
        
        int rightH=solve(root->right);
        if(root->left==NULL && root->right==NULL) return 1;
         if(root->left==NULL) return 1+rightH;
        if(root->right==NULL) return 1+leftH;
        
        return 1+min(leftH,rightH);
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};