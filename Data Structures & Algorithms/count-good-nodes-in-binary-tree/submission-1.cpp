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
private:
int good(TreeNode* node, int currMax) {
    if (!node) return 0;
    int count = (node->val >= currMax) ? 1 : 0;
    currMax = max(currMax, node->val);
    return count + good(node->left, currMax) + good(node->right, currMax);
}
public:
    int goodNodes(TreeNode* root) {
        // we count the root
        return good(root, root->val);
    }
};
