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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node=root;
        if(!node) return NULL;
        else
        {
            invertTree(node->left);
            invertTree(node->right);
            TreeNode* temp=NULL;
            if(node->left) temp=node->left;
            node->left=node->right;
            node->right=temp;
            

        }
        return root;
    }
};