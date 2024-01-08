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
    void solve(TreeNode* root, int low, int high, int& sum) {
    if (!root) {
        return;  // Base case: reached a null node
    }

    if (root->val < low) {
        solve(root->right, low, high, sum);  // Skip left subtree
    } else if (root->val > high) {
        solve(root->left, low, high, sum);   // Skip right subtree
    } else {
        // Include the current node in the sum
        sum += root->val;
        
        // Explore both subtrees since the current node's value is within the range
        solve(root->left, low, high, sum);
        solve(root->right, low, high, sum);
    }
}

    int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    solve(root, low, high, sum);
    return sum;
}

};