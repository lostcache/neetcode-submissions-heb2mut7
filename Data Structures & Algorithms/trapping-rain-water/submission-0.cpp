class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;

        int l = 0, r = height.size() - 1;

        int leftMax = height[l];
        int rightMax = height[r];

        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += max(leftMax - height[l], 0);
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += max(rightMax - height[r], 0);
            }
        }

        return res;
    }
};
