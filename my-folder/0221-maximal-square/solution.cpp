class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int DP[301][301];
        vector<int> hor(0, m);
        vector<int> ver(0, n);
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    DP[i][j] = 0;
                }
                else
                {
                    if (i == 0 || j == 0)
                    {
                        DP[i][j] = 1;
                        res = max(DP[i][j] * DP[i][j], res);
                        continue;
                    }
                    DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;
                    res = max(DP[i][j] * DP[i][j], res);
                }
            }
        }
        return res;
    }
};
