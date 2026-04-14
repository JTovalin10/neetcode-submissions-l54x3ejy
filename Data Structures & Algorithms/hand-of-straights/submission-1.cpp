class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count{};
        count.reserve(hand.size());
        for (int n : hand) count[n]++;

        sort(hand.begin(), hand.end());
        for (int n : hand) {
            if (count[n] > 0) {
                for (int i = n; i < n + groupSize; i++) {
                    if (count[i] == 0) return false;
                    count[i]--;
                }
            }
        }
        return true;
    }
};
