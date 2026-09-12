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
    bool Check(TreeNode* temp1, TreeNode* temp2)
    {
        if(temp1==nullptr && temp2==nullptr) return true;
        if(!temp1 || !temp2 || temp1->val!=temp2->val) return false;
        bool a  = Check(temp1->left,temp2->right);
        bool b = Check(temp1->right,temp2->left);
        return a&&b;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return Check(root->left,root->right);
    }
};