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
class BSTIterator {
public:
    stack<TreeNode* >s;
    void AddLeft(TreeNode* root, stack<TreeNode* >&s)
    {
        TreeNode*curr=root;
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
    }
    BSTIterator(TreeNode* root) {
        AddLeft(root,s);
    }
    
    int next() {
        int ans;
        if(!s.empty())
        {
            TreeNode* t=s.top();
            s.pop();
            if(t->right) AddLeft(t->right,s);
            ans=t->val;
        }
        
        return ans;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */