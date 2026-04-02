class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> cnt;
        for (const auto& ni : nums) {
            cnt[ni]++;
        }
        int idx = 0;
        for (const auto& [num, cnt]: cnt) {
            for (int i = 0; i < cnt; ++i) {
                nums[idx + i] = num;
            }
            idx += cnt;
        }
    }
};