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
    int maxi=0;
    void solve(TreeNode* root, int dir, int len)
    {
        if(root==NULL) return;
        if(len>maxi)
        {
            maxi=len;
        }
        if(dir==0)
        {
            solve(root->left,dir,1);
            solve(root->right,dir^1,len+1);
        }
        else
        {
            solve(root->right,dir,1);
            solve(root->left,dir^1,len+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return 0;
        solve(root->left,0,1);
        solve(root->right,1,1);
        return maxi;
    }
};