class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        // contains the index of the nums
        for (int i = 0; i < nums.size(); ++i) {
            int n1 = nums[i];
            if (n1 > 0) break; // everything is increasing so we cannot grab something
            if (i > 0 && n1 == nums[i - 1]) continue; // prevents duplicates
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = n1 + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    res.push_back({n1, nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;  // skip right dupes
                }
            }
        }
        return res;
    }
};
