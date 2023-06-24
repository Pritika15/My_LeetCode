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
        void PreOrder(TreeNode *root,unordered_map<int,TreeNode*>&m)
    {
        m.insert({root->val,root});
       if(root->left) PreOrder(root->left, m);
        if(root->right) PreOrder(root->right, m);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return NULL;
    unordered_map<int,TreeNode*>m;
    PreOrder(root,m);
    if(m.find(val)!=m.end())
    {
        return m[val];
    }
    return NULL;
    }
};