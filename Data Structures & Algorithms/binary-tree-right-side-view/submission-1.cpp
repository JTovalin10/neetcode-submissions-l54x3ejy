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
    vector<int> rightSideView(TreeNode* root) {
        // BFS and only add the bcak of the queue to the view
        vector<int> res{};
        if (!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            res.push_back(q.back()->val);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }
        return res;
    }
};
