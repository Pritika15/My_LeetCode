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
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        if(!root) return ans;
        // TreeNode* curr=root;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int maxi=INT_MIN;
        
        while(!q.empty())
        {
           int n=q.size();
            int sum=0;
            int l=1;
            for(int i=0;i<n;i++)
            {
                 TreeNode* temp=q.front().first;
                 int level=q.front().second;
                q.pop();
                 sum+=temp->val;
                 l=level;
                if(temp->left) q.push({temp->left,level+1});
                if(temp->right) q.push({temp->right,level+1});
            }
            if(maxi<sum)
            {
                maxi=sum;
                ans=l;
            }
            
            
        }
        
        return ans;
    }
};