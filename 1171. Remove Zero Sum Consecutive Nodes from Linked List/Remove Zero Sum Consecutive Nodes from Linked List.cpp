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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummy;
        int prefix_sum = 0;
        while (cur)
        {
            prefix_sum += cur->val;
            if (mp.find(prefix_sum) != mp.end())
            {
                ListNode* del = mp[prefix_sum]->next;
                int sum = prefix_sum;
                while (del != cur)
                {
                    sum += del->val;
                    mp.erase(sum);
                    del = del->next;
                }
                mp[prefix_sum]->next = cur->next;
                cur = mp[prefix_sum]->next;
            }
            else
            {
                mp[prefix_sum] = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};