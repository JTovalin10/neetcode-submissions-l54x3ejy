class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> st(s.begin(), s.end());
        for (const char& c : st) {
            int l = 0;
            int c_count = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) c_count++;
                // (r - l + 1) - c_count gives us the number of characets that arent c
                // we wnat to make the window smaller to find how many characets we must eject to be within k
                while ((r - l + 1) - c_count > k) {
                    if (s[l] == c) c_count--;
                    l++;
                }
                   res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
