class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited;
        for (int i = 0; i < m; i++)
        {
            vector<bool> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        int res = 0;
        queue<pair<int, int>> mQ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    res++;
                    mQ.push({i, j});
                    visited[i][j] = true;
                    while (!mQ.empty())
                    {
                        auto cur = mQ.front();
                        mQ.pop();
                        int curX = cur.first;
                        int curY = cur.second; 
                        for (int i = 0; i < 4; i++)
                        {
                            int nextX = curX + dir[i][0];
                            int nextY = curY + dir[i][1];
                            if (nextX > -1 && nextX < m && nextY > -1 && nextY < n && grid[nextX][nextY] == '1' && !visited[nextX][nextY])
                            {
                                mQ.push({nextX, nextY});
                                visited[nextX][nextY] = true;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
