class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int mid = 0;
        int row = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            int lower = matrix[mid][0];
            int upper = matrix[mid][n - 1];
            if (target >= lower && target <= upper)
            {
                row = mid;
                break;
            }
            else if (target < lower)
            {
                right = mid - 1;
            }
            else if (target > upper)
            {
                left = mid + 1;
            }
        }
        if (row == -1) return false;
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (target == matrix[row][mid])
            {
                return true;
            }
            else if (target < matrix[row][mid])
            {
                right = mid - 1;
            }
            else if (target > matrix[row][mid])
            {
                left = mid + 1;
            }
        }
        return false;
    }
};
