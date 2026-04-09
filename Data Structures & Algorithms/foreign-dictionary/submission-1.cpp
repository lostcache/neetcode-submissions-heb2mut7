class Solution {
private:
    map<char, unordered_set<char>> adj;
    map<char, bool> visited;
    string res;

    void initAdj(const vector<string>& words) {
        for (const string& wi: words) {
            for (const char c: wi) {
                this->adj[c];
            }
        }
    }

    bool constructDAGs(const vector<string>& words) {
        for (int i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];

            int minLen = min(w1.length(), w2.length());

            if (w1.substr(0, minLen) == w2.substr(0, minLen) && w1.length() > w2.length()) {
                return false;
            }

            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        return true;
    }

    bool dfs(char curr) {
        if (this->visited.find(curr) != this->visited.end()) {
            return this->visited[curr];
        }

        this->visited[curr] = true;

        for (const char nei: this->adj[curr]) {
            if (this->dfs(nei)) {
                return true;
            }
        }

        this->visited[curr] = false;
        res += curr;
        return false;
    }

public:
    string foreignDictionary(vector<string>& words) {
        this->initAdj(words);
        if (!this->constructDAGs(words)) return "";
        for (auto [c, _]: adj) {
            if (this->dfs(c)) {
                return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
