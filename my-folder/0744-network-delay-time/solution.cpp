class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); 
        for (auto &t: times)
        {
            adj[t[0]].push_back({t[2], t[1]});
        }
        
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
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

                if (dist[a.second] > dist[u] + a.first)
                {
                    dist[a.second] = dist[u] + a.first;
                    pq.push({dist[a.second], a.second});
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i < dist.size(); i++)
        {
            res = max(res, dist[i]);
        }
        
        return res == 1e9 ? -1 : res;
    }
};
