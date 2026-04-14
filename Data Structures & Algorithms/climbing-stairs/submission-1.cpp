class Solution {
private:
unordered_map<int, int> memo{};

public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (memo.contains(n)) return memo[n];
        memo[n] =  climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }
};
