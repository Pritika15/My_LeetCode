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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        if(root->left==NULL && root->right==NULL)
            return 0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp==NULL)
                    ans+=0;
                else if(temp!=NULL && i%2==0 && temp->left==NULL && temp->right==NULL)
                    ans+=temp->val;
                if(temp!=NULL)
                {
                        if(temp->left==NULL)
                        q.push(NULL);
                    else q.push(temp->left);
                    if(temp->right==NULL)
                        q.push(NULL);
                   else q.push(temp->right);
                }
                
            }
           
        }
         return ans;
    }
};