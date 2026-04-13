class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        int row = 0;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (target >= matrix[mid][0]) {
                row = mid;
                top = mid + 1;
            } else {
                bottom = mid - 1;
            }
        }

        cout << left << ' ' << right << endl;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < matrix[row][mid]) {
                right = mid - 1;
            } else if (target > matrix[row][mid]) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
