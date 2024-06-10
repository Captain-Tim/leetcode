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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second_half_head = reverseList(slow);
        ListNode* cur_first_half = head;
        ListNode* cur_second_half = second_half_head;
        while (cur_first_half != slow)
        {
            if (cur_first_half->val != cur_second_half->val)
            {
                reverseList(second_half_head);
                return false;
            }
            cur_first_half = cur_first_half->next;
            cur_second_half = cur_second_half->next;
        }
        reverseList(second_half_head);
        return true;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head)
        {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};