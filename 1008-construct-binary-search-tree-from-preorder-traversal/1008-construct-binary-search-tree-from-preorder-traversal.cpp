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
    TreeNode* BuildTree(vector<int>& preorder, int preStart, int preEnd,vector<int>& Inorder, int Instart, int Inend,map<int,int>&m)
    {
        if(preStart>preEnd || Instart>Inend) return NULL;
        
        int RootIndex=m[preorder[preStart]];
        int LeftPart=RootIndex-Instart;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        root->left=BuildTree(preorder,preStart+1,preStart+LeftPart,Inorder,Instart,Instart+LeftPart,m);
        root->right=BuildTree(preorder,preStart+LeftPart+1,preEnd,Inorder,RootIndex+1,Inend,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>Inorder=preorder;
        sort(Inorder.begin(),Inorder.end());
        map<int,int>m;
        for(int i=0;i<Inorder.size();i++) m[Inorder[i]]=i;
        
        TreeNode* root=BuildTree(preorder,0,preorder.size(),Inorder,0,Inorder.size()-1,m);
        return root;
    }
};