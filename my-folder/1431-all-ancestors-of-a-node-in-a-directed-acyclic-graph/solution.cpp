class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, set<int>> whoBlocks;
        for (int i = 0; i < n; i++)
        {
            whoBlocks[i] = {};
        }
        for (auto& p: edges)
        {
            whoBlocks[p[1]].insert(p[0]);
        }

        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int j: whoBlocks[cur])
                {
                    if (!visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                        whoBlocks[i].insert(j);
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(vector<int>(whoBlocks[i].begin(), whoBlocks[i].end()));
        }
        return res;
    }
};
