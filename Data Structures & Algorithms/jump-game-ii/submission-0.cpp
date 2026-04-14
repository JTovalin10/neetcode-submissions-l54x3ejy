class Solution {
public:
    int jump(const vector<int>& nums) {
        int l = 0, r = 0, curr = 0;
        while (r < nums.size() - 1) {
            int best = 0;
            for (int i = l; i <= r; i++) {
                best = max(best, nums[i] + i);
            }
            l = r + 1;
            r = best;
            curr++;
        }
        return curr;
    }
};
