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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) return nullptr;
        if (lists.size() == 1) {
            return lists[0];
        }

        auto head = this->merge(lists[0], lists[1]);

        for (int i = 2; i < lists.size(); ++i) {
            head = this->merge(head, lists[i]);
        }

        return head;
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* tail = nullptr;
        if (l1->val < l2->val) {
            tail = l1;
            l1 = l1->next;
        } else {
            tail = l2;
            l2 = l2->next;
        }

        ListNode* head = tail;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return head;
    }
};
