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
    bool PreOrder(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 || !root2) return root1==root2;
        if(root1->val!=root2->val) return false;
        return  PreOrder(root1->left,root2->right) && PreOrder(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
      return !root || PreOrder(root->left,root->right);
        
    }
};