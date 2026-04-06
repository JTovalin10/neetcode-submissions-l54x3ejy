class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set{};
        set.reserve(nums.size());
        for (const auto& num : nums) set.insert(num);
        int res{0};
        for (const auto& num : nums) {
            int tmp = num;
            int curr = 1;
            while (set.find(tmp - 1) != set.end()) {
                curr++;
                tmp--;
            }
            res = max(res, curr);
        }
        return res;
    }
};
