class Solution {
private:
unordered_map<int, int> memo{};

int dfs(const vector<int>& nums, int i) {
    if (i >= nums.size()) return 0;

    if (memo.contains(i)) return memo[i];

    memo[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
    return memo[i];
}

public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);   
    }
};
