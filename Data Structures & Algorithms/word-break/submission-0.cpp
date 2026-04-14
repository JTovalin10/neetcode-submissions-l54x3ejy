class Solution {
private:
unordered_map<int, bool> memo{};

bool find(const string& s, vector<string>& wordDict, int i) {
    if (memo.contains(i)) return memo[i];
    for (const string& w : wordDict) {
        if (i + w.size() <= s.length() && s.substr(i, w.length()) == w) {
            if (find(s, wordDict, i + w.length())) {
                memo[i] = true;
                return true;
            }
        }
    }
    memo[i] = false;
    return false;
}

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.reserve(s.size());
        memo[s.size()]  = true;
        return find(s, wordDict, 0);    
    }
};
