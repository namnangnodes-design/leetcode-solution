class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int numR = grid.size();
        int numC = grid[0].size();
        if (numR < 3 || numC < 3) return 0;
        int res = 0;
        for (int i = 0; i <= numR - 3; i++)
        {
            for (int j = 0; j <= numC - 3; j++)
            {
                int valid = true;
                vector<int> countNum(16, 0);
                countNum[grid[i][j]]++;
                countNum[grid[i][j + 1]]++;
                countNum[grid[i][j + 2]]++;
                countNum[grid[i + 1][j]]++;
                countNum[grid[i + 1][j + 1]]++;
                countNum[grid[i + 1][j + 2]]++;
                countNum[grid[i + 2][j]]++;
                countNum[grid[i + 2][j + 1]]++;
                countNum[grid[i + 2][j + 2]]++;
                for (int k = 1; k <= 9; k++)
                {
                    if (countNum[k] != 1)
                    {
                        valid = false;
                        break;
                    }
                }
                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15)
                {
                    valid = false;
                    continue; 
                }

                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != 15)
                {
                    valid = false;
                    continue; 
                }
                if (valid)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
