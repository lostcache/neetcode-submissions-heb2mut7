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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return nullptr;

        int N = 0;
        auto node = head;
        while (node != nullptr) {
            node = node->next;
            N++;
        }

        if (n == N) {
            auto temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int curr_idx = 0;
        node = head;
        while (node != nullptr) {
            if (N - curr_idx == n + 1) {
                auto temp = node->next;
                node->next = node->next->next;
                delete temp;
                break;
            }
            node = node->next;
            curr_idx++;
        }

        return head;
    }
};
