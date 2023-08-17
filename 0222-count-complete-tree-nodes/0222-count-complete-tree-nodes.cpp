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
    int height(TreeNode* root, int c)
    {
        TreeNode* curr=root;
        int h=1;
        while(curr)
        {
            h++;
            if(c==1)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
            
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int LeftH=height(root->left,1);
        int rightH=height(root->right,0);
        
        if(LeftH==rightH) return pow(2,LeftH)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};