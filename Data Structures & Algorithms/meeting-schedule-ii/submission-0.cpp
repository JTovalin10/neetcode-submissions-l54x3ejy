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
        vector<pair<int, int>> records{};
        for (const auto& it : intervals) {
            records.push_back({it.start, 1});
            records.push_back({it.end, -1});
        }
        sort(records.begin(), records.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int curr = 0, res = 0;
        for (const auto& rec : records) {
            curr += rec.second;
            res = max(res, curr);
        }
        return res;
    } 
};
