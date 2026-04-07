class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n - 1;
        while (l < r) {
            // i is used to adjust for the position of unprocessed outer layer indices
            // top is top, bottom is bottom, l is left, r is right.
            // movement is in clockwise
            // top left moves to right, hence, [top][l + i]
            // top right moves down, hence, [top + i][r]
            // bottom right moves left, hence, [bottom][r - i]
            // bottom left moves up, hence, [bottom - i][l]
            for (int i = 0; i < r - l; ++i) {
                int top = l, bottom = r;

                int topLeft = matrix[top][l + i];

                // top-left <- bottom-left
                matrix[top][l + i] = matrix[bottom - i][l];

                // bottom-left <- bottom-right
                matrix[bottom -i][l] = matrix[bottom][r - i];

                // bottom-right <- top-right
                matrix[bottom][r - i] = matrix[top + i][r];

                // top-right <- top-left
                matrix[top + i][r] = topLeft;
            }
            r--, l++;
        }
    }
};
