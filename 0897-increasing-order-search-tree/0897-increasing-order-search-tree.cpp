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
    void Inorder(vector<int>&ans,TreeNode* root)
    {
        if(root->left) Inorder(ans,root->left);
        ans.push_back(root->val);
        if(root->right) Inorder(ans,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        Inorder(ans,root);
        TreeNode* ansNode=new TreeNode(ans[0]);
        TreeNode* temp=ansNode;
        for(int i=1;i<ans.size();i++)
        {
            temp->left=NULL;
            temp->right= new TreeNode(ans[i]);
            temp=temp->right;
        }
        return ansNode;
        
    }
};