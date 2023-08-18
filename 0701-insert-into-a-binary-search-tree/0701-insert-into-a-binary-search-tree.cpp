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
    // bool isLeaf(TreeNode* root)
    // {
    //     if(root->right==NULL && root->left==NULL) return true;
    //     return false;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* node=new TreeNode(val);
            return node;
        }
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->val < val)
            {
                 if(curr->right==NULL)
                {curr->right= new TreeNode(val);
                 break;
                }
                curr=curr->right;
            }
            else
            {
                if(curr->left==NULL)
                {curr->left= new TreeNode(val);
                 break;
                }
                curr=curr->left;
            }
        }
        return root;
    }
};