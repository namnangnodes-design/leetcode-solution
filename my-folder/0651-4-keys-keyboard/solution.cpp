class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n && i <= 5; i++)
        {
            dp[i] = i;
        }

        for (int i = 6; i <= n; i++)
        {
            for (int j = 3; j <= 6; j++)
            {
                dp[i] = max(dp[i], dp[i - j] + dp[i - j] * (j - 2));
            }
        }
        return dp[n];
    }
};
