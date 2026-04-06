class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, int> m1{};
        m1.reserve(n);
        unordered_map<char, int> m2{};
        m2.reserve(n);

        for (int i{0}; i < n; i++) {
            char c1 = s[i];
            char c2 = t[i];
            m1[c1] += 1;
            m2[c2] += 1;
        }
        return m1 == m2;
    }
};
