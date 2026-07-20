class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        vector<int> res;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.push_back(grid[i][j]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cur = i * n + j;
                grid[i][j] = res[(m * n + (cur - k % (m * n))) % (m * n) ];
            }
        }
        return grid;
    }
};
