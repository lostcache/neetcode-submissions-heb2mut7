class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        auto countLeq = [&](int num) {
            return ((upper_bound(nums1.begin(), nums1.end(), num) - nums1.begin()) +
                    (upper_bound(nums2.begin(), nums2.end(), num)) - nums2.begin());
        };

        auto findKthSmallest = [&](int k) {
            int lo, hi;
            if (nums1.empty()) {
                lo = nums2.front(), hi = nums2.back();
            } else if (nums2.empty()) {
                lo = nums1.front(), hi = nums1.back();
            } else {
                lo = min(nums1.front(), nums2.front());
                hi = max(nums1.back(), nums2.back());
            }
            int res = hi;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (countLeq(mid) >= k) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return res;
        };

        int total = nums1.size() + nums2.size();
        if (total % 2) {
            return findKthSmallest(total / 2 + 1);
        } else {
            return (findKthSmallest(total / 2) + findKthSmallest(total / 2 + 1)) / 2.0;
        }

    }
};
