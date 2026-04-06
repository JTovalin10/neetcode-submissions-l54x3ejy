class Solution {
public:
    int trap(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        int l = 0, r = n - 1;
        int lMax = 0, rMax = 0;
        while (l < r) {
            if (heights[l] < heights[r]) {
            // parse smaller ones first
                lMax = max(lMax, heights[l]);
                res += max(0, lMax - heights[l]);
                l++;
            } else {
                rMax = max(rMax, heights[r]);
                res += max(0, rMax - heights[r]);
                r--;
            }
        }
        return res;
    }
};
