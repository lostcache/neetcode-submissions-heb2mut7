/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // for this problem-space map is faster than unordered_map
        map<Node*, Node*> m;

        Node* headcpy = new Node(head->val);
        m[head] = headcpy;

        Node* curr = head;
        Node* currcpy = headcpy;

        while (curr) {
            Node* randcpy = NULL;
            if (curr->random) {
                if (m.find(curr->random) != m.end()) {
                    randcpy = m[curr->random];
                } else {
                    randcpy = new Node(curr->random->val);
                    m[curr->random] = randcpy;
                }
            }
            currcpy->random = randcpy;

            Node* nextcpy = NULL;
            if (curr->next) {
                if (m.find(curr->next) != m.end()) {
                    nextcpy = m[curr->next];
                } else {
                    nextcpy = new Node(curr->next->val);
                    m[curr->next] = nextcpy;
                }
            }
            currcpy->next = nextcpy;

            curr = curr->next;
            currcpy = currcpy->next;
        }

        return headcpy;
    }
};
