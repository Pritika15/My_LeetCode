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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
         queue<pair<TreeNode*,pair<int,int>>>q;
         map<int,map<int,multiset<int>>>m;
         q.push({root,{0,0}});
         while(!q.empty())
         {
            TreeNode*n=q.front().first;
             int verti=q.front().second.first;
             int level=q.front().second.second;
             q.pop();
             m[verti][level].insert({n->val});
             if(n->left) q.push({n->left,{verti-1,level+1}});
             if(n->right) q.push({n->right,{verti+1,level+1}});
         }
         
         for(auto v:m)
         {
             vector<int>temp;
             for(auto vv:v.second)
             {
                temp.insert(temp.end(),vv.second.begin(),vv.second.end());
             }
             ans.push_back(temp);
             
         }
         return ans;
    }
};