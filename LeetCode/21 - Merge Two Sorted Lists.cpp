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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        for (ListNode* ptr=head; l1 || l2; ptr = ptr->next) {
            if ( NULL == l1 ) {
                ptr->next = l2;
                break;
            }
            else if ( NULL == l2 ) {
                ptr->next = l1;
                break;
            }

            if ( l1->val < l2->val )
                ptr->next = l1, l1 = l1->next;
            else
                ptr->next = l2, l2 = l2->next;
        }

        return head->next;
    }
};
