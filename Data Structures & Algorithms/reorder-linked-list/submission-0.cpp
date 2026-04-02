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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        if (head->next == nullptr) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* other_half = slow->next;
        slow->next = nullptr;
        ListNode* curr = other_half;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        other_half = prev;

        while (head != nullptr && other_half != nullptr) {
            ListNode* temp1 = head->next;
            ListNode* temp2 = other_half->next;

            head->next = other_half;
            other_half->next = temp1;

            head = temp1;
            other_half = temp2;
        }
    }
};
