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
    int FindH(TreeNode* root, int &maxi)
    {
        if(!root) return 0;
        int LH=FindH(root->left,maxi);
        int RH=FindH(root->right,maxi);
        maxi=max(maxi,(LH+RH));
        
        return 1+max(LH,RH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi=0;
        FindH(root,maxi);
        return maxi;
    }
};