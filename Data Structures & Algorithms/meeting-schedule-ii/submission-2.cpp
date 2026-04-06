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
    int minMeetingRooms(vector<Interval>& intervals) {
        auto cmp = [](const Interval& a, const Interval& b) {
            return a.end > b.end;
        }; 
        priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);

        sort (intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        int res = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            while (pq.size() != 0 && pq.top().end <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i]);
            res = max(res, (int)pq.size());
        }
        return res;
    }
};
