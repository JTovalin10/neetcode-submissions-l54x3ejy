class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk{};
        for (int i{}; i < n; ++i) {
            int temp = temperatures[i];
            while (!stk.empty() && temperatures[stk.top()] < temp) {
                int day = stk.top(); stk.pop();
                int diff = i - day;
                res[day] = diff;
            }
            stk.push(i);
        }
        return res;
    }
};
