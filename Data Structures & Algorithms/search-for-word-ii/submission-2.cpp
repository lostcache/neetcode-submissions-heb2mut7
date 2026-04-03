class TrieNode {
public:
    int idx;
    bool isWord;
    vector<TrieNode*> nei;
    TrieNode() {
        this->nei = vector<TrieNode*> (26, nullptr);
        this->idx = -1;
        this->isWord = false;
    }
};

class Solution {
private:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    TrieNode* t = nullptr;

    TrieNode* makeTrie(vector<string>& wa) {
        this->t = new TrieNode();

        for (int i = 0; i < wa.size(); ++i) {
            const auto& w = wa[i];
            TrieNode* curr = this->t;
            for (const char c: w) {
                if (curr->nei[c - 'a'] == nullptr) {
                    curr->nei[c - 'a'] = new TrieNode();
                }
                curr = curr->nei[c - 'a'];
            }
            curr->isWord = true;
            curr->idx = i;
        }

        return t;
    }

    void dfs(TrieNode* curr, const auto& wa, const auto& b, int i, int j, auto& vst, auto& sol, auto& p) {
        if (vst[i][j] || curr == nullptr) return;

        if (curr->isWord && p.find(curr->idx) == p.end()) {
            sol.push_back(wa[curr->idx]);
            p.insert(curr->idx);
        }


        vst[i][j] = true;

        for (auto [di, dj]: this->dirs) {
            int ni = i + di;
            int nj = j + dj;

            if (ni < 0 || ni >= b.size() || nj < 0 || nj >= b[0].size()) continue;

            char c = b[ni][nj];
            dfs(curr->nei[c - 'a'], wa, b, ni, nj, vst, sol, p);
        }

        vst[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        TrieNode* t = this->makeTrie(words);
        vector<string> sol;
        unordered_set<int> p;
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                vector<vector<bool>> vst = vector<vector<bool>>(b.size(), vector<bool>(b[0].size(), false));
                dfs(t->nei[b[i][j] -  'a'], words, b, i, j, vst, sol, p);
            }
        }
        return sol;
    }
};
