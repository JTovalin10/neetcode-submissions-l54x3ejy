class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts{};
        counts.reserve(nums.size());
        for (const auto& num : nums) {
            counts[num]++;
        }
        // now we want to put them in buckets by frequency
        unordered_map<int, std::vector<int>> freqs{};
        freqs.reserve(nums.size());
        for (const auto& [num, freq] : counts) {
            freqs[freq].push_back(num);
        }
        int count = 0;
        vector<int> res{};
        res.reserve(k);
        for (int i = nums.size(); i >= 0; i--) {
            // we found a match
            if (freqs.find(i) != freqs.end()) {
                for (const auto& num : freqs[i]) {
                    if (count == k) return res;
                    res.push_back(num);
                    count++;
                }
            }
        }
        return res;
    }
};
