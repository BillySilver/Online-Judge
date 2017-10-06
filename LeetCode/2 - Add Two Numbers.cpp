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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ( !l1 )
            return l2;
        if ( !l2 )
            return l1;

        int carry = 0, sum;
        ListNode *head = new ListNode(-1), *tail = head;
        while ( l1 && l2 ) {
            sum   = l1->val + l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        tail->next = l1 ? l1 : l2;
        while ( carry ) {
            if ( NULL == tail->next ) {
                tail->next = new ListNode(carry);
                break;
            }

            tail  = tail->next;
            sum   = tail->val + carry;
            carry = sum / 10;
            tail->val = sum % 10;
        }

        return head->next;
    }
};
