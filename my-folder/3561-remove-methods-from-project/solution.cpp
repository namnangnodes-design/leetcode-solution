class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int is = invocations.size();
        unordered_map<int, unordered_set<int>> invoke;
        unordered_map<int, unordered_set<int>> invokedBy;
        for (auto &i: invocations)
        {
            invokedBy[i[0]].insert(i[1]);
            invoke[i[1]].insert(i[0]);
        }

        vector<int> res;
        unordered_set<int> del;

        queue<int> q;
        q.push(k);
        del.insert(k);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int next: invokedBy[cur])
            {
                if (del.find(next) == del.end())
                {
                    del.insert(next);
                    q.push(next);
                }
            }
        }

        bool needDel = true;
        for (int d: del)
        {
            for (int i: invoke[d])
            {
                if (del.find(i) == del.end())
                {
                    needDel = false;
                    break;
                }
            }
            if (!needDel)
            {
                break;
            }
        }
        if (!needDel) del.clear();   
        for (int i = 0; i < n; i++)
        {
            if (del.find(i) == del.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
