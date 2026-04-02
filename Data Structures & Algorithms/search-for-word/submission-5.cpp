class Solution {
private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool existsHelper(vector<vector<char>>& b, string& w, int idx, int i, int j, vector<vector<bool>>& vst) {
        if (idx >= w.length()) return false;

        if (b[i][j] != w[idx]) return false;

        if (idx == w.length() - 1) return true;

        vst[i][j] = true;
        
        for (auto [di, dj]: this->dirs) {
            int ni = i + di, nj = j + dj;

            if (ni < 0 || ni >= b.size() || nj < 0 || nj >= b[0].size()) {
                continue;
            }

            if (vst[ni][nj]) continue;
            
            if (existsHelper(b, w, idx + 1, ni, nj, vst)) {
                return true;
            }
        }

        vst[i][j] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool>> vst(board.size(), vector<bool>(board[0].size(), false));
                // if (word.length() == 1 && board[i][j] == word[0]) return true;
                if (this->existsHelper(board, word, 0, i, j, vst)) {
                    return true;
                }
            }
        }
        return false;
    }
};
