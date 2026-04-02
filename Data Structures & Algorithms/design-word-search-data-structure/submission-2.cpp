class Node {
public:
    vector<Node*> nei;
    bool word;
    Node() {
        this->word = false;
        this->nei = vector<Node*> (26, nullptr);
    };
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (const char c: word) {
            if (curr->nei[c - 'a'] == nullptr) {
                curr->nei[c - 'a'] = new Node();
            }
            curr = curr->nei[c - 'a'];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(const string& word, int index, Node* current) {

        if (current == nullptr) return false;

        if (index == word.length()) {
            return current->word;
        }

        if (word[index] == '.') {

            for (int childIndex = 0; childIndex < 26; ++childIndex) {
                if (searchHelper(word, index + 1, current->nei[childIndex])) {
                    return true;
                }
            }
            return false;
        }

        return searchHelper(
            word,
            index + 1,
            current->nei[word[index] - 'a']
        );
    }


};
