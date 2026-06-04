class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 10000000));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (auto &e: edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (dist[u][v] > dist[u][i] + dist[i][v])
                    {
                        dist[u][v] = dist[u][i] + dist[i][v];
                    }

                    if (dist[v][u] > dist[v][i] + dist[i][u])
                    {
                        dist[v][u] = dist[v][i] + dist[i][u];
                    }
                }
            }
        }

        int res = -1;
        int smallest = n + 1;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                {
                    temp++;
                }
            }
            if (temp <= smallest)
            {
                res = i;
                smallest = temp;
            }
        }

        return res;
    }
};
