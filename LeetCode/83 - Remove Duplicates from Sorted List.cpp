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
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode* ptr = head; ptr; ptr = ptr->next) {
            ListNode* chk;
            for (chk = ptr->next; chk; chk = chk->next)
                if ( chk->val != ptr->val )
                    break;

            ptr->next = chk;
        }

        return head;
    }
};
