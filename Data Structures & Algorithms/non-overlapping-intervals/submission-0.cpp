class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1];
        int res{};
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start < prevend) {
                res++;
                prevend = min(prevend, end);
            } else {
                prevend = end;
            }
        }
        return res;
    }
};
