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
     vector<TreeNode*> solve(int l,int r)
     {
          vector<TreeNode*>ans;
         if(l>r||l<1)
         {
             vector<TreeNode*>v;
             v.push_back(NULL);
             return v;
         }
          if(l==r)
         {
             vector<TreeNode*>v;
             TreeNode* temp= new TreeNode;
             temp->val=l;
             temp->left=NULL;
             temp->right=NULL;
             v.push_back(temp);
             return v;
         }
         //vector<TreeNode*>ans;
         for(int i=l;i<=r;i++)
         {
            vector<TreeNode*> lt=solve(l,i-1);
             vector<TreeNode*> rt=solve(i+1,r);
             
             for(int k=0;k<lt.size();k++)
             {
                 for(int m=0;m<rt.size();m++)
                 {
                      TreeNode* temp= new TreeNode;
                     temp->val=i;
                     temp->left=lt[k];
                     temp->right=rt[m];
                     ans.push_back(temp);
                 }
            
             }
         }
         return ans;
     }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};