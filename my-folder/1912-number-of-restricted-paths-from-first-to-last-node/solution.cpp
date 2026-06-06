class Solution {
public:
    int mN;
    vector<long long> dist; 
    vector<vector<pair<int, int>>> adj;
    vector<int> memo;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        mN = n;
        dist.clear();
        adj.clear();
        memo.clear();
        
        dist = vector<long long>(n + 1, 1e18); 
        adj = vector<vector<pair<int, int>>>(n + 1);
        dist[n] = 0;
        for (auto &e: edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, n});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) 
            {
                continue;
            }
            for (auto &a: adj[u])
            {
                int w = a.first;
                int v = a.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        memo = vector<int>(n + 1, -1);
        return dp(1);
    }

    int dp(int cur)
    {
        if (cur == mN) return 1;
        if (memo[cur] != -1)
        {
            return memo[cur];
        }
        long long current_sum = 0;
        for (auto &a: adj[cur])
        {
            int next = a.second;
            if (dist[cur] > dist[next])
            {
                current_sum += dp(next); 
                current_sum %= 1000000007;
            }
        }
        return memo[cur] = current_sum;
    }
};
