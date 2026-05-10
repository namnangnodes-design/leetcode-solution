class Solution {
public:
    vector<int> mUnion;
    int mCount;

    int find(int i)
    {
        if (mUnion[i] == i)
        {
            return i;
        }
        return mUnion[i] = find(mUnion[i]);
    }

    void unite(int i, int j)
    {
        int findI = find(i);
        int findJ = find(j);
        if (findI == findJ)
        {
            return;
        }
        mCount--;
        mUnion[findI] = findJ; 
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        mUnion.clear();
        for (int i = 0; i < n; i++)
        {
            mUnion.push_back(i);
        }
        mCount = n;
        for (auto& log: logs)
        {
            unite(log[1], log[2]);
            if (mCount == 1)
            {
                return log[0];
            }
        }
        return -1;
    }
};
