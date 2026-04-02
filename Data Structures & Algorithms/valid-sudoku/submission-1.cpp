class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row_set(9, 0), col_set(9, 0), box_set(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue;
                if (row_set[i] & (1 << val)) {
                    return false;
                }
                if (col_set[j] & (1 << val)) {
                    return false;
                }
                int box_row = i / 3;
                int box_col = j / 3;
                int box_idx = box_row * 3 + box_col;
                if (box_set[box_idx] & (1 << val)) {
                    return false;
                }
                row_set[i] |= (1 << val);
                col_set[j] |= (1 << val);
                box_set[box_idx] |= (1 << val);
            }
        }
        return true;
    }
};
