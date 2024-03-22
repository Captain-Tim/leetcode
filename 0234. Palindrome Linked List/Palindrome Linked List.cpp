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
private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    
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
        ListNode* cur_right = second_half_head;
        ListNode* cur_left = head;
        bool res = true;
        while (cur_left != slow)
        {
            if (cur_left->val != cur_right->val)
            {
                res = false;
                break;
            }
            cur_left = cur_left->next;
            cur_right = cur_right->next;
        }
        // restore the list
        reverseList(second_half_head);
        return res;
    }
};

