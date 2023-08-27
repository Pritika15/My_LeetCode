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
class RobOrNot
{
    public:
    int rob;
    int Notrob;
    
};
class Solution {
public:
    RobOrNot Robber(TreeNode* root)
    {
        if(!root) return {0,0};
        
        RobOrNot left=Robber(root->left);
        RobOrNot right=Robber(root->right);
        
        int RobVal=root->val+left.Notrob+right.Notrob;
        
        int NoRobVal=max(left.rob,left.Notrob)+max(right.rob,right.Notrob);
        
        return RobOrNot{RobVal,NoRobVal};
        
    }
    int rob(TreeNode* root) {
        RobOrNot ans=Robber(root);
        return max(ans.rob,ans.Notrob);
    }
};