class Solution {
public:
    vector<pair<int, int>> blanks;
    vector<vector<char>> result;
    int temp[9][9];
    int n;

    void solve(int pos)
    {
        if (pos == n)
        {
            for (int i = 0; i < 9; i++)
            {
                vector<char> rowI;
                for (int j = 0; j < 9; j++)
                {
                    rowI.push_back(temp[i][j] + '0');
                }
                result.push_back(rowI);
            }
            return;
        }
        int row = blanks[pos].first;
        int col = blanks[pos].second;
        for (int i = 1; i <= 9; i++)
        {
            bool valid = true;
            for (int j = 0; j < 9; j++)
            {
                if (temp[row][j] == i || temp[j][col] == i)
                {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            int blockR = row / 3 * 3;
            int blockC = col / 3 * 3;
            for (int j = blockR; j < blockR + 3; j++)
            {
                for (int k = blockC; k < blockC + 3; k++)
                {
                    if (temp[j][k] == i)
                    {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (!valid) continue;
            temp[row][col] = i;
            solve(pos + 1);
            temp[row][col] = -1;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    blanks.push_back({ i, j });
                    temp[i][j] = -1;
                    continue;
                }
                temp[i][j] = board[i][j] - '0';
            }
        }
        n = blanks.size();
        solve(0);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = result[i][j];
            }
        }
    }
};
