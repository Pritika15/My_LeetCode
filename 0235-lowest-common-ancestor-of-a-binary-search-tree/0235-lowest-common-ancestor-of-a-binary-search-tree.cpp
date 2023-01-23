/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool inorder(TreeNode* root, TreeNode* target, vector<TreeNode*>&temp)
    {
        if(!root) return false;
        temp.push_back(root);
        if(root==target) return true;
        if((inorder(root->left,target,temp))|| (inorder(root->right,target,temp))==true)
            return true;
        temp.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        inorder(root,p,path1);
        inorder(root,q,path2);
        int n=path1.size();
        int m=path2.size();
        TreeNode* ans;
        if(n<m)
        {
             for(int i=0;i<n;i++)
             {
                 if(path1[i]==path2[i])
                 {
                     ans=path1[i];
                 }
                 else if(path1[i]!=path2[i])
                     break;
             }
        }
        else
        {
           for(int i=0;i<m;i++)
             {
                 if(path1[i]==path2[i])
                 {
                     ans=path1[i];
                 }
                 else if(path1[i]!=path2[i])
                     break;
             } 
        }
        return ans;
       
        
    }
};