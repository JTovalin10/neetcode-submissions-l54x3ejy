class Solution {
private:
unordered_map<int, int> memo{};
int n;

int dfs(const string& s, int i) {
    if (memo.contains(i)) return memo[i];
    if (s[i] == '0') return 0;
    int res = dfs(s, i + 1);
    if (i + 1 < n && (s[i] == '1'|| s[i] == '2' && s[i + 1] <= '6')) {
        res += dfs(s, i + 2);
    }
    memo[i] = res;
    return res;
}

public:
   int numDecodings(const string& s) {
        n = s.size();
        memo.reserve(n);
        memo[n] = 1;
        return dfs(s, 0);
    }
};
