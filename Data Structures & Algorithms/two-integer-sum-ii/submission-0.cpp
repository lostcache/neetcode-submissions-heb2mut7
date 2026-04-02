class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int tar = target - numbers[i];
            int l = i + 1, r = numbers.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (numbers[m] == tar) {
                    return { i + 1, m + 1 };
                } else if (numbers[m] < tar) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return { -1, -1 };
    }
};
