class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int val;
    Node (int _key, int _val) {
        this->key = _key;
        this->val = _val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    Node* tail;
    Node* head;
    unordered_map<int, Node*> m;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->tail = nullptr;
        this->head = nullptr;
    }

    int get(int key) {
        if (this->m.find(key) == this->m.end()) return -1;

        Node* curr = this->m[key];

        if (this->head == curr) {
            return curr->val;
        }

        if (this->tail == curr) {
            curr->prev->next = nullptr;
            this->tail = curr->prev;
            curr->next = this->head;
            this->head->prev = curr;
            this->head = curr;
            curr->prev = nullptr;
            return curr->val;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        this->head->prev = curr;
        curr->next = this->head;
        this->head = curr;
        this->head->prev = nullptr;
        return curr->val;
    }

    void put(int key, int value) {
        if (this->m.find(key) != this->m.end()) {
            int _ = this->get(key);
            this->head->val = value;
            return;
        }

        if (!this->m.size()) {
            this->head = new Node(key, value);
            this->tail = this->head;
            this->m[key] = this->head;
            return;
        }

        // insert at head
        Node* prevHead = this->head;
        this->head = new Node(key, value);
        this->head->next = prevHead;
        prevHead->prev = this->head;
        this->m[key] = this->head;

        while (this->m.size() > this->cap) {
            // delete tail
            Node* prevTail = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            this->m.erase(prevTail->key);
            delete prevTail;
        }
    }
};