class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if (o[0][0] == 1)
        {
            return 0;
        }
        int m = o.size();
        int n = o[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (o[i][0])
            {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (o[0][i])
            {
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (o[i][j] == 1) 
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
