class Solution {
public:
    int largestRectangleArea(const vector<int>&  heights) {
        const int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk{};
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();

         for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        
        int res{};
        for (int i = 0; i < n; ++i) {
            left[i] += 1;
            right[i] -= 1;
            res = max(res, heights[i] * (right[i] - left[i] + 1));
        }
        return res;
    }
};
