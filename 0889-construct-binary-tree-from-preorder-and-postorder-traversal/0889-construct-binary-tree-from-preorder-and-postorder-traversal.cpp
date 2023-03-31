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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int *preIndex, int l, int h, int size)
    {
        if(l>h || *preIndex>=size) return NULL;
        
        TreeNode* root= new TreeNode(preorder[*preIndex]);
        ++*preIndex;
        
        if(l==h) return root;
        
        int i;
        for(i=l;i<=h;++i)
        {
            if(preorder[*preIndex]==postorder[i])
                break;
        }
        
        if(i<=h)
        {
            root->left=solve(preorder,postorder,preIndex,l,i,size);
            root->right=solve(preorder,postorder,preIndex,i+1,h-1,size);
            
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        int preIndex=0;
        return solve(preorder,postorder,&preIndex,0,n-1,n);
    }
};