class Solution {
public:

    // can we eat all bananas with the given rate in the allocated time
    bool speed(const vector<int>& piles, int rate, int time) {
        int count = 0;
        for (const auto& num : piles) {
            count += (num + rate - 1) / rate;
            if (count > time) return false;
        }
        return true;
    }

    int minEatingSpeed(const vector<int>& piles, int h) {
        int max_val = *max_element(piles.begin(), piles.end());
        int l = 1, r = max_val;
        // we are doing a binary search based on the h being the upper bound
        while (l < r) {
            int rate = l + (r - l) / 2;
            bool within_time = speed(piles, rate, h);
            if (within_time) {
                r = rate;
            }  else {
                l = rate + 1;
            }
        }
        return l;
    }
};
