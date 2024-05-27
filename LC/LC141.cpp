/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* prev = head;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            cur = cur->next->next;
            prev = prev->next;
            if(cur == prev)
            {
                return true;
            }
        }
        return false;
    }
};