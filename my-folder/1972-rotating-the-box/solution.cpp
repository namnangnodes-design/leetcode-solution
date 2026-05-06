class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for (int i = 0; i < m; i++)
        {
            int stone = 0;
            int start = 0;
            for (int j = 0; j < n; j++)
            {
                if (boxGrid[i][j] == '#')
                {
                    stone++;
                }
                else if (boxGrid[i][j] == '*')
                {
                    for (int k = start; k < j; k++)
                    {
                        boxGrid[i][k] = '.';
                        if (k >= j - stone)
                        {
                            boxGrid[i][k] = '#';
                        }
                    }
                    stone = 0;
                    start = j + 1;
                }
                if (j == n - 1)
                {
                    for (int k = start; k < n; k++)
                    {
                        boxGrid[i][k] = '.';
                        if (k >= n - stone)
                        {
                            boxGrid[i][k] = '#';
                        }
                    }
                    stone = 0;
                    start = j + 1;
                }
            }
        }
        vector<vector<char>> transpose(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                transpose[i][j] = boxGrid[m - 1 - j][i];
            }
        }
        return transpose;
    }
};
/*
0->1  
0     0 = 0 1
1     0 = 0 0
*/
