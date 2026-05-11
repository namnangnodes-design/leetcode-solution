class Solution {
public:
    unordered_map<int, int> mUnion;

    int find(int i)
    {
        if (mUnion.find(i) == mUnion.end())
        {
            mUnion[i] = i;
        }

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


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            if (!unite(edges[i][0], edges[i][1]))
            {
                return edges[i];
            }
        }
        return {};
    }
};
