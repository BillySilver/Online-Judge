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
    ListNode* swapPairs(ListNode* head) {
        if ( NULL == head )
            return NULL;
        if ( NULL == head->next )
            return head;

        ListNode* newTail = swapPairs(head->next->next);
        ListNode* newHead = head->next;
        head->next->next = head;
        head->next       = newTail;

        return newHead;
    }
};
