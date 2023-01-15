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
    void print(TreeNode* root,vector<string> &ans,string s)
    {
        if(root==NULL) return;
        s+=to_string(root->val)+"->";
        if(root->left==NULL && root->right==NULL)
        {
            s.erase(s.length()-2,2);
            ans.push_back(s);
            
        }
        print(root->left,ans,s);
        print(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        print(root,ans,s);
        return ans;
    }
};