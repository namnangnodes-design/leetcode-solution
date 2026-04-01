class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> pMap;
        vector<int> res;
        int n = pid.size();
        for (int i = 0; i < n; i++)
        {
            pMap[ppid[i]].push_back(pid[i]); 
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(kill);
        visited[kill] = true;
        res.push_back(kill);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i: pMap[cur])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
