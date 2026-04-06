/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        Interval& curr = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (curr.end > intervals[i].start) return false;
            curr = intervals[i];
        }
        return true;
    }
};
