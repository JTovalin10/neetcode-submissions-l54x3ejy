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
TreeNode* find(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (!node) return nullptr;
    TreeNode* res = node;
    if (node->val > p->val && node->val > q->val) res = find(node->left, p, q);
    if (node->val < p->val && node->val < q->val) res = find(node->right, p, q);
    return res;
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};
