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
    void Find(TreeNode* root,int &maxi, int &mini)
    {
        if(!root) return ;
        if(root->val >maxi) maxi=root->val;
        if(root->val<mini) mini=root->val;
        if(root->left) Find(root->left,maxi,mini);
        if(root->right) Find(root->right,maxi,mini);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int FinalAns= -1e9;
       

        int maxi = -1e9, mini = 1e9;
        Find(root, maxi, mini);
        FinalAns = max(FinalAns, abs(root->val - maxi));
        FinalAns = max(FinalAns, abs(root->val - mini));

        if (root->left) {
            FinalAns = max(FinalAns, maxAncestorDiff(root->left));
        }
        if (root->right) {
            FinalAns = std::max(FinalAns, maxAncestorDiff(root->right));
        }

        return FinalAns;
    }
};