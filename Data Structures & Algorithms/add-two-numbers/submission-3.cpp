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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1 = l1, * c2 = l2, * rh = new ListNode(), * rc = rh;

        bool carry = false;
        while (c1 || c2) {
            int currVal = 0;
            if (c1) currVal += c1->val;
            if (c2) currVal += c2->val;
            currVal += carry;
            
            carry = currVal >= 10;
            currVal %= 10;
            rc->val = currVal;

            if ((c1 && c1->next) || (c2 && c2->next) || carry) rc->next = new ListNode();

            if (c1) c1 = c1->next;
            if (c2) c2 = c2->next;
            rc = rc->next;
        }

        while (carry) {
            int currVal = rc->val + carry;
            carry = currVal >= 10;
            rc->val = currVal %= 10;
            if (carry) rc->next = new ListNode();
            rc = rc->next;
        }

       return rh;
    }
};
