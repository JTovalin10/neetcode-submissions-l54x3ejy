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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        while (tmp1 != nullptr || tmp2 != nullptr || carry > 0) {
            int sum = carry;
            if (tmp1 != nullptr) {
                sum += tmp1->val;
                tmp1 = tmp1->next;
            }
            if (tmp2 != nullptr) {
                sum += tmp2->val;
                tmp2 = tmp2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy->next;
    }
};
