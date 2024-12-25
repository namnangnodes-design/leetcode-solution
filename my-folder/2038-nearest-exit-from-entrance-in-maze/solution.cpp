class Solution {
public:
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int dx[4] = { 0, 1, 0, -1 };
            int dy[4] = { -1, 0, 1, 0 };
            vector<vector<bool>> visited;
            for (int i = 0; i < maze.size(); i++)
            {
                vector<bool> temp;
                visited.push_back(temp);
                for (int j = 0; j < maze.at(0).size(); j++)
                {
                    visited.at(i).push_back(false);
                }
            }
            int minStep = maze.size() * maze.at(0).size();
            bool done = false;
            queue<int> xQueue;
            queue<int> yQueue;
            queue<int> step;
            yQueue.push(entrance.at(0));
            xQueue.push(entrance.at(1));
            visited.at(entrance.at(0)).at(entrance.at(1)) = true;
            step.push(0);
            while (!xQueue.empty())
            {
                int x = xQueue.front();
                int y = yQueue.front();
                int cur = step.front();
                xQueue.pop();
                yQueue.pop();
                step.pop();
                for (int i = 0; i < 4; i++)
                {
                    int xN = x + dx[i];
                    int yN = y + dy[i];
                    //cout << "y = " << yN << " x = " << xN << " maze = " << entrance.at(0) << " " <<entrance.at(1) << endl;
                    if (xN >= 0 && xN < maze.at(0).size() && yN >= 0 && yN < maze.size() && maze.at(yN).at(xN) == '.' && !visited.at(yN).at(xN) && cur <= minStep && (yN != entrance.at(0) || xN != entrance.at(1)))
                    {
                        if (yN == maze.size() - 1 || xN == 0 || xN == maze.at(0).size() - 1 || yN == 0)
                        {
                            minStep = min(minStep, cur + 1);
                            done = true;
                        }
                        xQueue.push(xN);
                        yQueue.push(yN);
                        step.push(cur + 1);
                        visited.at(yN).at(xN) = true;
                    }
                }
            }
            if (done)
            {
                return minStep;
            }
            
            return -1;
        }
};
