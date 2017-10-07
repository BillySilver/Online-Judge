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
        bool ans = false;

        for (ListNode *ptr = head; ptr; ) {
            // Cycle detected.
            if ( intptr_t(ptr->next) & 1 ) {
                ans = true;
                break;
            }

            ptr->next = (ListNode*)(intptr_t(ptr->next) | 1);
            ptr = (ListNode*)(intptr_t(ptr->next) ^ 1);
        }

        // Recovery the list.
        for (ListNode* ptr = head; ptr; ) {
            if ( 0 == (intptr_t(ptr->next) & 1) )
                break;

            ptr->next = (ListNode*)(intptr_t(ptr->next) & ~1);
            ptr = ptr->next;
        }

        return ans;
    }
};
