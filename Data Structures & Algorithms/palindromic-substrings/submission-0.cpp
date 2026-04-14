class Solution {
public:
    int countSubstrings(const string& s) {
        int n = s.size();
        vector<vector<bool>> check(n, vector<bool>(n, false));
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && ((j - i) <= 2 || check[i + 1][j - 1])) {
                    res++;
                    check[i][j] = true;
                }
            }
        }
        return res;
    }
};
