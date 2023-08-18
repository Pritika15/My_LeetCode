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
     TreeNode* build(vector<int>&inorder, vector<int>&postorder, int is, int ie, int ps, int pe, map < int, int > &inOr){
        if((ps > pe) || (is > ie))
            return NULL;
        
        int ind = inOr[postorder[pe]];
        int nelem = ind - is;

        TreeNode* root = new TreeNode(postorder[pe]);
        root->left =  build(inorder, postorder,    is,  ind - 1, ps, ps + nelem - 1, inOr);
        root->right = build(inorder, postorder, ind+1,  ie, ps + nelem, pe-1, inOr);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postLen = postorder.size();
        int inLen = inorder.size();
        if(postLen != inLen)
            return NULL;
        map<int,int>inOr;
        for(int i=0;i<inorder.size();i++) inOr[inorder[i]]=i;
        
        TreeNode* root= build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,inOr);
        
        return root;
    }
  
};