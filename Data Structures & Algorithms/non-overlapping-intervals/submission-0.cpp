class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (currEnd <= intervals[i][0]) {
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
                continue;
            }

            if (currEnd > intervals[i][1]) {
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
            res++;
        }

        return res;
    }
};
