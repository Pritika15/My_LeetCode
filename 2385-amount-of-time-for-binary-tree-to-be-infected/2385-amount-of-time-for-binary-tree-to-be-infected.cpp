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
    void MakeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    TreeNode* Find(TreeNode* root, int start)
{
    if (root == nullptr) return nullptr; // Base case: node not found
    if (root->val == start) return root; // Base case: node found

    TreeNode* leftResult = Find(root->left, start);   // Search in the left subtree
    if (leftResult) return leftResult; // If found in the left subtree, return it

    TreeNode* rightResult = Find(root->right, start); // Search in the right subtree
    return rightResult; // Return whatever is found in the right subtree (could be nullptr)
}

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        MakeParent(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        
        TreeNode* target=Find(root,start);
        // cout<<target->val<<endl;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            for(int i=0;i<size;i++)
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
        return level-1;
        
    }
};