class Solution {
public:

    int find_min(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int bs(const vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;

            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int inflect = find_min(nums);
        int res = bs(nums, target, 0, inflect - 1);
        if (res != -1) return res;
       return bs(nums, target, inflect, nums.size() - 1);
    }
};
