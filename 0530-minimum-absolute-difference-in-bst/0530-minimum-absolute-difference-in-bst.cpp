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
    void helper(TreeNode* root, vector<int>&v)
    {
        if(root==NULL) return;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        int Mini=INT_MAX;
        int n=v.size();
        for(int i=n-1;i>0;i--)
        {
            int curr=abs(v[i]-v[i-1]);
            if(curr<Mini) Mini=curr;
        }
            return Mini ;
    }
};