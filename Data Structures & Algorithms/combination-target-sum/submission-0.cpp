class Solution {
public:
vector<vector<int>> res{};
    vector<vector<int>> combinationSum(const vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, target, curr, 0);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, int target, vector<int>& curr, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || i >= nums.size()) return;

        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], curr, i);
        curr.pop_back();
        backtrack(nums, target, curr, i + 1);
    }
};
