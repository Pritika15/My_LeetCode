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
    void Mapping(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&childToParent)
    {
//         BFS
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t->left) 
            {
                childToParent[t->left]=t;
                q.push(t->left);
            }
             if(t->right) 
            {
                childToParent[t->right]=t;
                q.push(t->right);
            }
        }
    }
    TreeNode* Find(TreeNode* root, int start)
    {
//         DFS Preorder
        if(!root) return NULL;
        if(root->val==start) return root;
       
        TreeNode* l=Find(root->left,start);
        if(l) return l;


        TreeNode* r=Find(root->right,start);
        return r;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>childToParent;
        Mapping(root,childToParent);
        unordered_map<TreeNode*,bool>vis;
        TreeNode* st=Find(root,start);
        
        queue<pair<TreeNode*,int>>q;
        q.push({st,0});
        vis[st]=1;
        int totalTime=0;
        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int time=q.front().second;
            q.pop();
            
//             left-child
            if(temp->left && !vis[temp->left])
            {
                q.push({temp->left,time+1});
                vis[temp->left]=1;
            }
            
            //             right-child
            if(temp->right && !vis[temp->right])
            {
                q.push({temp->right,time+1});
                 vis[temp->right]=1;
            }
//             parent
            if(childToParent[temp] && !vis[childToParent[temp]])
            {
                q.push({childToParent[temp],time+1});
                vis[childToParent[temp]]=1;
            }
            totalTime=time;
        }
        return totalTime;
    }
};