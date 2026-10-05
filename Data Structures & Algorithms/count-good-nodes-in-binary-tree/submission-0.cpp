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
int dfs(TreeNode* node, int maxSoFar) {
    if (node == NULL) return 0;        // what should an empty node return?

    int count = 0;
    if (node->val>=maxSoFar) count = 1;            // rule 1

    maxSoFar = max(maxSoFar,node->val);                // rule 2

    count += dfs(node->right, maxSoFar);   // go left
    count += dfs(node->left, maxSoFar);   // go right
    return count;
}
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
