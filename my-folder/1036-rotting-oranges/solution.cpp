class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = { -1, 0, 1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<int> xQueue;
        queue<int> yQueue;
        queue<int> tQueue;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                if (grid[i][j] == 2)
                {
                    xQueue.push(i);
                    yQueue.push(j);
                    tQueue.push(0);
                }
            }
        }
        if (fresh == 0)
        {
            return time;
        }
        while (!xQueue.empty())
        {
            int mX = xQueue.front();
            int mY = yQueue.front();
            int mT = tQueue.front();
            xQueue.pop();
            yQueue.pop();
            tQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int nX = mX + dx[i];
                int nY = mY + dy[i];
                if (nX >= 0 && nX < grid.size() && nY >= 0 && nY < grid[0].size() && grid[nX][nY] == 1)
                {
                    tQueue.push(mT + 1);
                    time = max(mT + 1, time);
                    if (--fresh == 0)
                    {
                        return time;
                    }
                    xQueue.push(nX);
                    yQueue.push(nY);
                    grid[nX][nY] = 2;
                }
            }
        }
        return -1;
    }
};
