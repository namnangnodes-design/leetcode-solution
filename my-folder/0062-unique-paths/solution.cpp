class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
        {
            return 1;
        }
        double result = 1;
        for (int i = 1; i <= n - 1; i++)
        {
            result = result * (m - 1 + i) / i;
        }
        return (int) result;
    }
};
