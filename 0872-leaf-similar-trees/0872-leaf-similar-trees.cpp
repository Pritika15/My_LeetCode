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
    bool isLeaf(TreeNode* root)
    {
        if(!root->left && !root->right) return true;
        return false;
    }
    void Inorder(TreeNode* root,vector<int>&v)
    {
        if(!root) return;
        if(root->left) Inorder(root->left,v);
        if(isLeaf(root)) v.push_back(root->val);
        if(root->right) Inorder(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        Inorder(root1,v1);
        Inorder(root2,v2);
        return v1==v2;
    }
};