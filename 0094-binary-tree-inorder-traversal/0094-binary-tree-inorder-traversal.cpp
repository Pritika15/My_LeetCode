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
    void solve(TreeNode* node,vector<int>&ans,stack<TreeNode*>&s)
    {
        s.push(node);
        if(node->left!=NULL)
            solve(node->left,ans,s);
        if(node->left==NULL && !s.empty() )
        {
           int x=s.top()->val;
            ans.push_back(x);
            s.pop();
        }
        if(node->right!=NULL)
        {
            solve(node->right,ans,s);
        }
       if(node->right==NULL && !s.empty())
        {
           int x=s.top()->val;
            ans.push_back(x);
            s.pop();
        }
        
            
    }
    vector<int> inorderTraversal(TreeNode* root) {
      //iterative inorder trvaersal
        vector<int> ans;
        if(root==NULL)
            return ans;
            
        
        stack<TreeNode*>s;
        solve(root,ans,s);
        return ans;
        
    }
};