class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // find how long it will take each index to reach the target
        int n = position.size();
        vector<pair<int, int>> diffs(n);
        for (int i = 0; i < n; i++) {
            diffs[i] = {position[i], speed[i]};
        }
        sort(diffs.rbegin(), diffs.rend());
        vector<double> stk;
        for (const auto& [pos, spd] : diffs) {
            stk.push_back((double)(target - pos) / spd);
            if (stk.size() >= 2 && stk.back() <= stk[stk.size() - 2]) stk.pop_back();
        }
        return stk.size();
    }
};
