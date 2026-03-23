class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> minGr(m, vector<long long>(n, 0));
        vector<vector<long long>> maxGr(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    maxGr[i][j] = grid[0][0];
                    minGr[i][j] = grid[0][0];
                }
                else if (i == 0)
                {
                    maxGr[i][j] = maxGr[i][j - 1] * grid[i][j];
                    minGr[i][j] = minGr[i][j - 1] * grid[i][j];
                }
                else if (j == 0)
                {
                    maxGr[i][j] = maxGr[i - 1][j] * grid[i][j];
                    minGr[i][j] = minGr[i - 1][j] * grid[i][j];
                }
                else
                {
                    maxGr[i][j] = max(max(maxGr[i - 1][j] * grid[i][j], minGr[i - 1][j] * grid[i][j]), max(maxGr[i][j - 1] * grid[i][j], minGr[i][j - 1] * grid[i][j]));
                    minGr[i][j] = min(min(maxGr[i - 1][j] * grid[i][j], minGr[i - 1][j] * grid[i][j]), min(maxGr[i][j - 1] * grid[i][j], minGr[i][j - 1] * grid[i][j]));
                }
            }
        }
        return maxGr[m - 1][n - 1] >= 0 ? maxGr[m - 1][n - 1] % 1000000007 : -1;
    }
};
