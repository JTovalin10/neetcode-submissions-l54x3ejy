class Solution {
private:
int n;
// -1 = unvisited, 0 = false, 1 = true
vector<vector<int>>memo{};

bool dfs(const vector<int>& nums, int i, int target) {
    if (i == nums.size()) return false;
    if (target < 0) return false;
    if (target == 0) return true;
    if (memo[i][target] != -1) return memo[i][target];
    memo[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
    return memo[i][target];

}

public:
    bool canPartition(vector<int>& nums) {
        int target =accumulate(nums.begin(), nums.end(), 0);
        if ((target) % 2 != 0) return false;
        target /= 2;
        memo.resize(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target);
    }
};
