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
    void PushAll(TreeNode* root, stack<TreeNode*>&s)
    {
        // if(root) s.push(root);
         TreeNode* curr=root;
        while(curr)
        {
            s.push(curr);
            curr=curr->left;
        }
            
            
    }
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        PushAll(root,s);
    }
    
    int next() {
        int ans=s.top()->val;
        
        TreeNode* rightSubTree=s.top()->right;
        s.pop();  
        PushAll(rightSubTree,s);

            
          
        return ans;
            
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */