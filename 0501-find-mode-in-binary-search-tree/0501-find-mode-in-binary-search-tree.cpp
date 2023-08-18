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
    void PreOrder(TreeNode* root, unordered_map<int,int>&m)
    {
        if(m.find(root->val)==m.end()) m[root->val]=1;
        else m[root->val]++;
        
        if(root->left) PreOrder(root->left,m);
        if(root->right) PreOrder(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>m;
        PreOrder(root,m);
        // cout<<m.size()<<endl;
        int maxi=0;
        for(auto it:m)
        {
            maxi=max(maxi,it.second);
            // cout<<maxi<<" "<<it.second<<endl;
        }
        for(auto it:m)
        {
            if(it.second==maxi) ans.push_back(it.first);
        }
        
        return ans;
    }
};