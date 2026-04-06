class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, r = row * col - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int curr = matrix[mid / col][mid % col];
            if (curr == target) return true;

            if (curr > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
