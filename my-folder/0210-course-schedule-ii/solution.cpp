class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> blockWhos;
        unordered_map<int, unordered_set<int>> whoBlocks;
        for (int i = 0; i < numCourses; i++)
        {
            blockWhos[i] = {};
            whoBlocks[i] = {};
        }
        vector<int> res;
        queue<int> mQ;
        for (auto& p: prerequisites)
        {
            blockWhos[p[1]].insert(p[0]);
            whoBlocks[p[0]].insert(p[1]);
        }
        for (auto& w: whoBlocks)
        {
            if (w.second.size() == 0) 
            {
                mQ.push(w.first);
            }
        }
        while (!mQ.empty())
        {
            int cur = mQ.front();
            mQ.pop();
            res.push_back(cur);
            for (int b: blockWhos[cur])
            {
                whoBlocks[b].erase(cur);
                if (whoBlocks[b].size() == 0) 
                {
                    mQ.push(b);
                }
            }
        }
        if (res.size() == numCourses)
        {
            return res;
        }
        return {};
    }
};
