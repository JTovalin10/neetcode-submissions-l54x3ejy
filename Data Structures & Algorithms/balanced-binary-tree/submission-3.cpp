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

#include <array>

class Solution {
private:
array<int, 2> dfs(TreeNode* node) {
    if (!node) return {1, 0};
    
    array<int, 2> left = dfs(node->left);
    array<int, 2> right = dfs(node->right);

    bool balanced = (left[0] == 1 && right[0] == 1) && (abs(left[1] - right[1]) <= 1);
    int height = 1 + max(left[1], right[1]);
    return {(balanced ? 1 : 0), height};
}

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
};
