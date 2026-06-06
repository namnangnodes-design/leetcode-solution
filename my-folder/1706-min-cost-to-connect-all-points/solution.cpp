class Solution {
public:
    int mN;
    vector<int> mUnion;

    int find(int i)
    {
        if (mUnion[i] == i)
        {
            return mUnion[i];
        }
        mUnion[i] = find(mUnion[i]);
        return mUnion[i];
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
        mN--;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> adj;
        mN = points.size();
        mUnion = vector<int>(mN, -1);
        for (int i = 0; i < mN; i++)
        {
            mUnion[i] = i;
        }
        for (int i = 0; i < mN; i++)
        {
            for (int j = i + 1; j < mN; j++)
            {
                int u = i;
                int v = j;
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push({d, u, v});
            }
        }
        int res = 0;
        while (mN > 1 && !adj.empty())
        {
            auto a = adj.top();
            adj.pop();
            int u = a[1];
            int v = a[2];
            int d = a[0];
            if (unite(u, v))
            {
                res += d;
            }

        }
        return res;
    }
};
