class Solution {
  
public:
    int uniquePaths(int m, int n) {
        vector<int> bottom(n, 1), curr(n, 0);
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (j + 1 < n) curr[j] += curr[j + 1];
                curr[j] += bottom[j];
            }
            bottom = curr;
            curr = vector<int>(n, 0);
        }
        return bottom[0];
    }
};
