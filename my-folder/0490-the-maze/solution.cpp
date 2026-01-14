class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> road;
        bool visited[101][101][2];
        for (int i = 0; i < maze.size(); i++)
        {
            for (int j = 0; j < maze[0].size(); j++)
            {
                visited[i][j][0] = false;
                visited[i][j][1] = false;
        
            }
        }
        road.push({start[0], start[1]});
        while (!road.empty())
        {
            pair<int, int> cur = road.front();
            road.pop();
            int x = cur.first;
            int y = cur.second;
            visited[cur.first][cur.second][0] = true;
            visited[cur.first][cur.second][1] = true;
            //left
            while (y > 0 && maze[x][y - 1] == 0 && !visited[x][y - 1][0])
            {
                visited[x][y - 1][0] = true;
                y--;
            }
            if (x == destination[0] && y == destination[1]) return true;
            if (y != cur.second)
            {
                road.push({x, y});
            }
            x = cur.first;
            y = cur.second;
            //right
            while (y < maze[0].size() - 1 && maze[x][y + 1] == 0 && !visited[x][y + 1][0])
            {
                visited[x][y + 1][0] = true;
                y++;
            }
            if (x == destination[0] && y == destination[1]) return true;
            if (y != cur.second)
            {
                road.push({x, y});
            }
            x = cur.first;
            y = cur.second;
            //up
            while (x > 0 && maze[x - 1][y] == 0 && !visited[x - 1][y][1])
            {
                visited[x - 1][y][1] = true;
                x--;
            }
            if (x == destination[0] && y == destination[1]) return true;
            if (x != cur.first)
            {
                road.push({x, y});
            }
            x = cur.first;
            y = cur.second;            
            //down
            while (x < maze.size() - 1 && maze[x + 1][y] == 0 && !visited[x + 1][y][1])
            {
                visited[x + 1][y][1] = true;
                x++;
            }
            if (x == destination[0] && y == destination[1]) return true;
            if (x != cur.first)
            {
                road.push({x, y});
            }
            x = cur.first;
            y = cur.second;
        }
        return false;
    }
};
