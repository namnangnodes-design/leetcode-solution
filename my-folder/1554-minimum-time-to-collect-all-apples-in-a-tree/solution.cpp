class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> adj(n);
        for (auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        vector<int> order;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto a: adj[cur])
            {
                if (!visited[a])
                {
                    parent[a] = cur;
                    order.push_back(a);
                    q.push(a);
                    visited[a] = true;
                }
            }
        }
        int res = 0;
        for (int i = n - 2; i > -1; i--)
        {
            int c = order[i];
            int p = parent[c];
            if (hasApple[c])
            {
                res += 2;
                hasApple[p] = true;
            }
        }
        return res;
    }
};
