class Solution {
private:
unordered_map<int, int> memo{};

int dfs(vector<int>& nums, int i, int end) {
    if (i > end) return 0;
    if (memo.contains(i)) return memo[i];
    memo[i] = max(dfs(nums, i + 1, end), nums[i] + dfs(nums, i + 2, end));
    return memo[i];
}

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = dfs(nums, 0, nums.size() - 2);
        memo.clear();
        int r = dfs(nums, 1, nums.size() - 1);
        return max(l , r);
    }
};
