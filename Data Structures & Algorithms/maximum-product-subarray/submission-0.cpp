class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1, currMax = 1;
        for (int num : nums) {
            int tmp = currMax * num; // store for min
            currMax = max(max(currMax * num, currMin * num), num);
            currMin = min(min(tmp, currMin * num), num);
            res = max(res, currMax);
        }
        return res;
    }
};
