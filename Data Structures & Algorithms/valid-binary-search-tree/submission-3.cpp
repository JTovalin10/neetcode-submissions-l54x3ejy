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
bool isValid(TreeNode* node, int lower, int upper) {
    if (!node) return true;
    if (node->val <= lower || node->val >= upper) return false;
    return isValid(node->left, lower, node->val) && isValid(node->right, node->val, upper); 
} 

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};
