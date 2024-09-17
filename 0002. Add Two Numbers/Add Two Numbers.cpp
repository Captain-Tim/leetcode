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
        int carry = 0;
        ListNode dummy;
        ListNode* cur = &dummy;
        const int DECIMAL = 10;
        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            if (sum >= DECIMAL)
            {
                sum -= DECIMAL;
                carry = 1;
            }
            else
                carry = 0;
            cur->next = new ListNode(sum, nullptr);
            cur = cur->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};