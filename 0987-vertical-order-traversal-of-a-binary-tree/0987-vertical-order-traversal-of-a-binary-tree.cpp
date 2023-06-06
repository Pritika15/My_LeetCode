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
    void indexing(TreeNode* root, int i, int j, vector<pair<int,pair<int,int>>>&v)
    {
        v.push_back({i,{j,root->val}});
        if(root->left)
            indexing(root->left,i-1,j+1,v);
        if(root->right)
            indexing(root->right,i+1,j+1,v);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        vector<pair<int,pair<int,int>>>v; //first: index value, second: node value
        indexing(root,0,0,v);
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        // }
        int temp;
        for(int i=0;i<v.size();i++)
        {
            temp=v[i].first;
            vector<int>vv;
            vv.push_back(v[i].second.second);
            for(int j=i+1;j<v.size();j++)
            {
                if(temp==v[j].first)
                { vv.push_back(v[j].second.second);
                }
                else break;
                i=j;
            }
            ans.push_back(vv);
        }
        
        return ans;
    }
};