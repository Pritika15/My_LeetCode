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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int first,last;
            int mini=q.front().second;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                int currlevel=q.front().second-mini;
                q.pop();
                
                if(i==0) first=currlevel;
                if(i==size-1) last=currlevel;
                
                if(node->left) q.push({node->left,(long long)2*currlevel+1});
                if(node->right) q.push({node->right,(long long)2*currlevel+2});
            }
            ans=max(ans,(last-first+1));
        }
        return ans;
    }
};