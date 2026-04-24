class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int res = -1;
        while (l < r) {
            int lHeight = heights[l];
            int rHeight = heights[r];
            if (lHeight <= rHeight) {
                res = max(res, lHeight * (r - l));
                l++;
            } else {
                res = max(res, rHeight * (r - l));
                r--;
            }
        }
        return res;
    }
};
