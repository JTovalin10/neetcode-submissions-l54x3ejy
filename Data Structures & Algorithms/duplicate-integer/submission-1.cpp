class Solution {
public:
    bool hasDuplicate(const vector<int>& nums) {
        unordered_set<int> st{};
        st.reserve(nums.size());
        for (const auto& num : nums) {
            if (st.find(num) != st.end()) return true;
            st.insert(num);
        }
        return false;
    }
};