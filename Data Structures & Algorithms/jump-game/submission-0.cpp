class Solution {
public:
    bool canJump(const vector<int>& nums) {
        int n = nums.size() - 1;
        int reach = n;
        for (int i = n - 1; i >= 0; i--) {
            int max_jump = i + nums[i];
            if (max_jump >= reach) reach = i;
        }
        return reach == 0;
    }
};
