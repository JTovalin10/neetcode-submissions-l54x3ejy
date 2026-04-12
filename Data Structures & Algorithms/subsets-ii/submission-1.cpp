class Solution {
public:
    vector<vector<int>> res{};

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(nums, 0, curr);
        return res;
    }

    void backtrack(const vector<int>& nums, int i, vector<int>& curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(nums, i + 1, curr);
        curr.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        backtrack(nums, i + 1, curr);

        
    }
};
