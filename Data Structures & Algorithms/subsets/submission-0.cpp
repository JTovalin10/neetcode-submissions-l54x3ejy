class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sub(nums, 0, {});
        return {res.begin(), res.end()};
    }
private:
set<vector<int>> res{};

void sub(const vector<int>& nums, int index, vector<int> curr) {
    if (index > nums.size()) return;
    res.insert(curr);
    
    sub(nums, index + 1, curr);
    curr.push_back(nums[index]);
    sub(nums, index + 1, curr);
    curr.pop_back();
}
};
