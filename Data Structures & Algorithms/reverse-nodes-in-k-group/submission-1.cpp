
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* revHead = nullptr;
        ListNode* curr = head;
        ListNode* prev_grp_end = nullptr;
        while (curr) {
            // traverse
            int curr_grp_size = 1;
            ListNode* curr_grp_start = curr, * curr_grp_end = curr_grp_start;
            while (true) {
                if (!curr_grp_end->next || curr_grp_size >= k) break;
                curr_grp_end = curr_grp_end->next;
                curr_grp_size++;
            }

            // record next grp start before reversing
            curr = curr_grp_end->next;

            // can form group of k
            if (curr_grp_size == k) {

                // reverse the list for k nodes
                ListNode* curr_rev = curr_grp_start;
                ListNode* prev = nullptr;
                for (int i = 0; i < k; ++i) {
                    ListNode* temp = curr_rev->next;
                    curr_rev->next = prev;
                    prev = curr_rev;
                    curr_rev = temp;
                }

                // switch start and end pointers after reversing
                swap(curr_grp_start, curr_grp_end);
            }


            if (revHead == nullptr) {
                revHead = curr_grp_start;
            }

            // connect curr reversed with prev reversed;
            if (prev_grp_end) prev_grp_end->next = curr_grp_start;
            prev_grp_end = curr_grp_end;
        }

        return revHead;
    }
};
