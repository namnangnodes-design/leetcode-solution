class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Use adjacency list + topo order instead of BFS from every node
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites)
        {
            graph[p[0]].push_back(p[1]);   // edge: p[0] -> p[1]
            indegree[p[1]]++;
        }

        static const int MAXN = 100;       // upper bound from constraints
        vector<bitset<MAXN>> whoBlocks(numCourses); // whoBlocks[v][u] = true if u is prerequisite of v

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);                 // start topo from sources
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nxt : graph[cur])
            {
                // All prerequisites of cur are also prerequisites of nxt
                whoBlocks[nxt] |= whoBlocks[cur];   // propagate indirect prerequisites
                whoBlocks[nxt].set(cur);            // add direct prerequisite
                if (--indegree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }

        vector<bool> res;
        res.reserve(queries.size());       // avoid repeated reallocations
        for (int i = 0; i < (int)queries.size(); i++)
        {
            int u = queries[i][0], v = queries[i][1];
            res.push_back(whoBlocks[v].test(u)); // O(1) query via bitset
        }
        return res;
    }
};
