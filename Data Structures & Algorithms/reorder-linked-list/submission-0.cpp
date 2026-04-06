/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        head = change(head, head->next);
    }

    ListNode* change(ListNode* root, ListNode* curr) {
        if (curr == nullptr) return root;
        

        root = change(root, curr->next);
        if (root == nullptr) return nullptr;

        ListNode* tmp = nullptr;
        if (root == curr || root->next == curr) {
            curr->next = nullptr;
        } else {
            tmp = root->next;
            root->next = curr;
            curr->next = tmp;
        }
        return tmp;
    }
};
