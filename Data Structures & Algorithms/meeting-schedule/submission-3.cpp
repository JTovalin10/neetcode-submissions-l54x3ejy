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
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for (int i =0; i < intervals.size() - 1; i++) {
            auto& i1 = intervals[i];
            auto& i2 = intervals[i + 1];
            int i1start = i1.start;
            int i1end = i1.end;
            int i2start = i2.start;
            if (i1start == i2start) return false;
            if (i2start < i1end) return false;
        }
        return true;
    }
};
