class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> map{};
        int i = 0;
        for (const auto& num : nums) {
            int diff = target - num;
            if (map.find(diff) != map.end()) {
                return {map[diff], i};
            }
            map[num] = i++;
        }
    }
};
