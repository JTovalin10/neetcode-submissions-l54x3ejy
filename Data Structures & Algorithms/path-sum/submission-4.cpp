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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum, 0);
    }

private:

bool dfs(TreeNode* node, int target, int curr) {
    if (!node) return false;
    curr += node->val;
    if (!node->left && !node->right && target == curr) return true;
    return dfs(node->left, target, curr) || dfs(node->right, target, curr);
}
};