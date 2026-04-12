class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = numeric_limits<int>::min();
        for (int num : nums) {
            currSum = max(currSum, 0);
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
