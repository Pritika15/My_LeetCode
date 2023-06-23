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
class BSTiterator{
    public:
    stack<TreeNode*>s;
    bool flag=true; // flag==true->next else before
    void AddVal(TreeNode* root,stack<TreeNode*>&s)
    {
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            s.push(curr);
            if(flag)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    BSTiterator(TreeNode* root,bool flagVal){
        flag=flagVal;
        AddVal(root,s);
    }
    int next()
    {
        int ans;
        if(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            ans=temp->val;
            if(flag)
            {
                if(temp->right) AddVal(temp->right,s);
            }
            else
            {
                if(temp->left) AddVal(temp->left,s);
            }
        }
        return ans;
    
    }
    

    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root,true);
        BSTiterator r(root,false);
        
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};