class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row_set(9), col_set(9), box_set(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue;
                if (row_set[i].find(val) != row_set[i].end()) {
                    return false;
                }
                if (col_set[j].find(val) != col_set[j].end()) {
                    return false;
                }
                int box_row = i / 3;
                int box_col = j / 3;
                int box_idx = box_row * 3 + box_col;
                if (box_set[box_idx].find(val) != box_set[box_idx].end()) {
                    return false;
                }
                row_set[i].insert(val);
                col_set[j].insert(val);
                box_set[box_idx].insert(val);
            }
        }
        return true;
    }
};
