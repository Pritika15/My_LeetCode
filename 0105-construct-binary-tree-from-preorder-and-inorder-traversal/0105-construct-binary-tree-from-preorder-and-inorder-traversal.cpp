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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inO;
        for(int i=0;i<inorder.size();i++) inO[inorder[i]]=i;
        
        TreeNode* root= buildTrees(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inO);
        return root;
        
        
            
    }
    TreeNode* buildTrees(vector<int> preorder,int preStart,int preEnd,vector<int> inorder,int inStart,int inEnd,map<int,int> &inList){



        if(preStart>preEnd || inStart>inEnd)return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);

        int inRoot=inList[preorder[preStart]];
        int inLeft=inRoot-inStart;

        root->left=buildTrees(preorder,preStart+1,preStart+inLeft,inorder,inStart,inStart+inLeft,inList);
        root->right=buildTrees(preorder,preStart+inLeft+1,preEnd,inorder,inRoot+1,inEnd,inList);

        return root;

    }
};