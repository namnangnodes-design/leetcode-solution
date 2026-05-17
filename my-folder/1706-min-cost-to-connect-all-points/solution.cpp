class Solution {
public:
    int mCount;
    int mRes;
    vector<int> mUnion;

    int find(int i)
    {
        if (mUnion[i] == i)
        {
            return i;
        }
        return mUnion[i] = find(mUnion[i]);
    }

    bool unite(int a, int b)
    {
        int findA = find(a);
        int findB = find(b);
        if (findA == findB)
        {
            return false;
        }
        mUnion[findA] = findB;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        mCount = 0;
        mRes = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            mUnion.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        sort(edges.begin(), edges.end());
        for (auto &e: edges)
        {
            int u = e[1];
            int v = e[2];
            int d = e[0];
            if (unite(u, v))
            {
                mCount++;
                mRes += d;
            }
            if (mCount == n - 1)
            {
                return mRes;
            }
        }
        return mRes;
    }
};
