/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void MakeParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left) 
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        MakeParent(root,parent);
        int currLevel=0;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty())
        {
            int sizee=q.size();
            if(currLevel==k) break;
            currLevel++;
            for(int i=0;i<sizee;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=true;
                    
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=true;
                   
                }
                if(parent[temp] && !vis[parent[temp]])
                {
                     q.push(parent[temp]);
                    vis[parent[temp]]=true;
                   
                }
            }
        }
        
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            ans.push_back(t->val);
        }
        return ans;
    }
};