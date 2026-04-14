class Solution {
private:
unordered_map<int, int> memo{};

int climb(const vector<int>& cost, int i) {
    if (i >= cost.size()) return 0;
    if (memo.contains(i)) return memo[i];
    memo[i] = cost[i] + min(climb(cost, i + 1), climb(cost, i + 2));
    return memo[i];
}
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = climb(cost, 0);
        memo.clear();
        int c2 = climb(cost, 1);
        return min(c1, c2);
    }
};
