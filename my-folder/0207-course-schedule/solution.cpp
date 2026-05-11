class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> blockWho;
        unordered_map<int, unordered_set<int>> whoBlock;
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < numCourses; i++)
        {
            blockWho[i] = {};
            whoBlock[i] = {};
        }

        for (auto &p: prerequisites)
        {
            blockWho[p[1]].insert(p[0]);
            whoBlock[p[0]].insert(p[1]);
        }

        for (auto &w: whoBlock)
        {
            if (w.second.size() == 0)
            {
                q.push(w.first);
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int b: blockWho[cur])
            {
                whoBlock[b].erase(cur);
                if (whoBlock[b].size() == 0) 
                {
                    q.push(b);
                }
            }
        }
        if (res.size() == numCourses)
        {
            return true;
        }
        return false;
    }
};
