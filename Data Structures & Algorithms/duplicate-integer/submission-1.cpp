class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;
        for (const auto& n: nums) {
            if (seen.find(n) != seen.end()) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};