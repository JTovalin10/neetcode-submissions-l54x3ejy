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
bool check_if_same(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if ((!p && q) || (p && !q)) return false;
    if (p->val != q->val) return false;
    return check_if_same(p->left, q->left) && check_if_same(p->right, q->right);
}

bool helper(TreeNode* p, TreeNode* q) {
    if (!p) return false;
    bool check = false;
    if (p->val == q->val) {
        check = check_if_same(p, q);
        if (check == true) return true;
        // otherwise keep looking
    }
    return helper(p->left, q) || helper(p->right, q);
}

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && subRoot) return false;
        if (root && !subRoot) return false;
        if (!root && !subRoot) return true;
        return helper(root, subRoot);
    }
};
