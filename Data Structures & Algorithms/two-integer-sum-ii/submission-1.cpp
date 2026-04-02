class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); ++i) {
            while (numbers[i] + numbers[r] > target) {
                r--;
            }
            if (numbers[i] + numbers[r] == target) {
                return {i + 1, r + 1};
            }
        }
        return {-1, -1};
    }
};
