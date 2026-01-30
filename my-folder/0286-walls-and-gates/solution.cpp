class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> road;
        m = rooms.size();
        if (m == 0) return; // Handle edge case
        n = rooms[0].size();
        const int INF = 2147483647; // Use const for clarity
        
        // Initialize queue with all gates
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) 
                    road.push({i, j});
            }
        }
        
        // Multi-source BFS from all gates
        while (!road.empty()) {
            auto [x, y] = road.front(); // C++17 structured binding
            road.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                // Inline boundary check and condition (eliminates function call overhead)
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && rooms[nx][ny] == INF) {
                    rooms[nx][ny] = rooms[x][y] + 1; // Update before enqueue for correctness
                    road.push({nx, ny});
                }
            }
        }
    }
};
