class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxVol = -1;

        while (l < r) {
            maxVol = max(maxVol, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxVol;
    }
};
