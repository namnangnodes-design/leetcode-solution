class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> mApples;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.clear();
        mApples.clear();
        for (bool a: hasApple)
        {
            mApples.push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
            adj.push_back({});
        }
        for (auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1);    
    }
    int dfs(int cur, int par)
    {
        int time = 0;
        for (auto a: adj[cur])
        {
            if (a == par) continue;
            int v = dfs(a, cur);
            if (mApples[a] || v) time += 2 + v;            
        }
        return time;
    }
};
