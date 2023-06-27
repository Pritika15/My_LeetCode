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
    void Inorder(TreeNode*  root,  stack<int>&s)
{
    if(root->right) Inorder(root->right, s);    
    s.push(root->val);
    if(root->left) Inorder(root->left, s);    
    
}
    int kthSmallest(TreeNode* root, int k) {
    stack<int>s;
    Inorder(root,s);
    int ans =-1;
    if(k>s.size()) return ans;
    while(k-- && !s.empty())
    {
        ans=s.top();
        s.pop();
    }
    return ans;
    }
};