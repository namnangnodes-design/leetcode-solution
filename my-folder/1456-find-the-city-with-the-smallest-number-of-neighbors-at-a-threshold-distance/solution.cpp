class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {      
        int res = -1;
        int smallest = 101;  
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, 10000000);
            dist[i] = 0;
            for (int j = 0; j < n; j++)
            {
                bool update = false;
                for (auto &e: edges)
                {
                    int u = e[0];
                    int v = e[1];
                    int w = e[2];
                    if (dist[u] + w < dist[v])
                    {
                        update = true;
                        dist[v] = dist[u] + w;
                    }
                
                    if (dist[v] + w < dist[u])
                    {
                        update = true;
                        dist[u] = dist[v] + w;
                    }
                }
                if (!update)
                {
                    break;
                }
            }
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (dist[j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if (count <= smallest)
            {
                smallest = count;
                res = i;
            }
        }


        return res;
    }
};
