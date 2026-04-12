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
    int res = numeric_limits<int>::min();

    int path(TreeNode* node) {
        if (!node) return 0;
        int left = path(node->left);
        int right = path(node->right);
        int curr_path = max(0, max(left, right)) + node->val;
        int create_split = max(0, left + right) + node->val;
        res = max(res, create_split);
        res = max(res, curr_path);
        return curr_path;
    }
public:
    int maxPathSum(TreeNode* root) {
        path(root);
        return res;
    }
};
