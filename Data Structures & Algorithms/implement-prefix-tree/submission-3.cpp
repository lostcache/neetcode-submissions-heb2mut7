class Node {
public:
    char v;
    bool isW;
    vector<Node*> n;
    Node(char c) {
        this->v = c;
        this->n = vector<Node*> (26, nullptr);
        this->isW = false;
    }

    bool isWord() { return this->isW; };

    void setWord() { this->isW = true; }
};

class PrefixTree {
    Node* root = nullptr;
public:
    PrefixTree() {
        this->root = new Node('*');
    }
    
    void insert(string word) {
        Node* curr = root;
        for (const char c: word) {
            if (curr->n[c - 'a'] == nullptr) {
                Node* n = new Node(c);
                curr->n[c - 'a'] = n;
            }
            curr = curr->n[c - 'a'];
        }
        curr->setWord();
    }
    
    bool search(string word) {
        auto curr = root;
        for (const char c: word) {
            if (curr->n[c - 'a'] == nullptr) return false;
            curr = curr->n[c - 'a'];
        }

        return curr->isWord();
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        for (const char c: prefix) {
            if (curr->n[c - 'a'] == nullptr) return false;
            curr = curr->n[c - 'a'];
        }

        return true;
    }
};
