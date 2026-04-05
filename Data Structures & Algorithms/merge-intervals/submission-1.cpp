class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (currEnd < intervals[i][0]) {
                res.push_back({currStart, currEnd});
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            } else {
                currStart = min(currStart, intervals[i][0]);
                currEnd = max(currEnd, intervals[i][1]);
            }
        }
        res.push_back({currStart, currEnd});
        return res;
    }
};
