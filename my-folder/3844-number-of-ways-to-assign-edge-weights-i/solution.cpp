class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto &e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n + 1, false);    
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int depth = -1;

        while (!q.empty())
        {
            int temp = q.size();
            for (int i = 0; i < temp; i++)
            {
                int cur = q.front();
                q.pop();
                for (auto &a: adj[cur])
                {
                    if (!visited[a])
                    {
                        visited[a] = true;
                        q.push(a);
                    }
                }
            }
            depth++;
        }

        long long res = 1;
        for (int i = 1; i < depth; i++)
        {
            res *= 2;
            res %= 1000000007;
        }

        return res;
    }
};
