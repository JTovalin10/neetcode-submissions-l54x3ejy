class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> count{};
        count.reserve(3);
        for (const auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            for (int i{0}; i < target.size(); i++) {
                if (t[i] == target[i]) count.insert(i);
            }
        }
        return count.size() == 3;
    }
};
