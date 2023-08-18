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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            
            temp->left=NULL;
            if(!st.empty())temp->right=st.top();
        }
    }
};