class Solution {
public:
    int DP[38] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int tribonacci(int n) {
        if (n == 1 || n == 2 || n == 0 || DP[n] != 0)
        {
            return DP[n];
        }
        DP[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        return DP[n];
    }
};
