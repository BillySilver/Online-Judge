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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *now = head, *next;
        while (now) {
            next = now->next;
            now->next = prev;

            prev = now;
            now  = next;
        }

        return prev;
    }
};
