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
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
       
        
        int maxWidth=0;
        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
             int firstIndex,lastIndex;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                int index=q.front().second-mini;
                 q.pop();
                if(i==0)
                {
                    firstIndex=index;
                }
                if(i==size-1)
                {
                    lastIndex=index;
                }
               
               
                if(node->left)
                {
                    q.push({node->left, (long long)index*2+1});
                }
                if(node->right)
                {
                    q.push({node->right, (long long)index*2+2});
                }
                
            }
            
            maxWidth=max(maxWidth,lastIndex-firstIndex+1);
        }
        return maxWidth;
    }
};