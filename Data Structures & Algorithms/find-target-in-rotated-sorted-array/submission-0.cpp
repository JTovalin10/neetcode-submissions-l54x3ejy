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

    int bs(const vector<int>& nums, int target) {
        int l = 0, r  = nums.size() - 1;
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
        vector<int> left(nums.begin(), nums.begin() + inflect);
        // peform on the left side and if we find it here then we dont have to do the riught side
        int res = bs(left, target);
        if (res != -1) return res;
        vector<int> right(nums.begin() + inflect, nums.end());
        res = bs(right, target);
        if (res != -1) return res + inflect;
        return -1;
    }
};
