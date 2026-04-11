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
// array[0]: {0 or 1}, 0 means unbalanced else balanced
// array[1]: height
array<int, 2> balanced(TreeNode* node) {
    if (node == nullptr) return {1, 0};

    array<int, 2> left = balanced(node->left);
    array<int, 2> right = balanced(node->right);
    bool bal = (left[0] == 1 && right[0] == 1) && (abs(left[1] - right[1]) <= 1);
    int height = 1 + max(left[1], right[1]);
    return {(bal ? 1 : 0), height};
}

public:
    bool isBalanced(TreeNode* root) {
        return balanced(root)[0] == 1;
    }
};
