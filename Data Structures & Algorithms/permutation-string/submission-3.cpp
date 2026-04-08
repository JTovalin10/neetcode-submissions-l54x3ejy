class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> char1(26, 0);
        vector<int> char2(26, 0);

        // create the window size
        for (int i = 0; i < s1.size(); i++) {
            char1[s1[i] - 'a']++;
            char2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i  = 0; i < 26; i++) {
            if (char1[i] == char2[i]) matches++;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            if (matches == 26) return true;

            int index = s2[r] - 'a';
            char2[index]++;
            if (char1[index] == char2[index]) {
                matches++;
            } else if  (char1[index]  + 1 == char2[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            char2[index]--;
            if (char1[index] == char2[index]) {
                matches++;
            } else if  (char1[index]  - 1 == char2[index]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
