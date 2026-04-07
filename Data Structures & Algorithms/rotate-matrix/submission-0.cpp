class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n - 1;
        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                int top = l, bottom = r;

                int topLeft = matrix[top][l + i];

                // bottom-left to top-left
                matrix[top][l + i] = matrix[bottom - i][l];

                // bottom-right to bottom-left
                matrix[bottom -i][l] = matrix[bottom][r - i];

                // top right to bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // top-left to top-right
                matrix[top + i][r] = topLeft;
            }
            r--, l++;
        }
    }
};
