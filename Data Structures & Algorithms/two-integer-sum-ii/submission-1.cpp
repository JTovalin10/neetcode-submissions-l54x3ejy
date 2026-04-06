class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[r] + numbers[l];
            if (sum == target) return {l + 1, r + 1};
            if (sum < target) {
                l++;
            } else {
                r--;
            }
        } 
        return {};
    }
};
