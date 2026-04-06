class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<std::string>> memo{};
        memo.reserve(strs.size());
        for (const auto& str : strs) {
            std::vector<int> count(26 ,0);
            for (const auto& c : str) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            memo[key].push_back(str);
        }
        vector<vector<string>> res{};
        res.reserve(memo.size());
        for (const auto& [key, value] : memo) {
            res.push_back(value);
        }
        return res;
    }
};
