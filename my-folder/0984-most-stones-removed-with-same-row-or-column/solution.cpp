class Solution {
public:
    unordered_map<int, int> parent;
    int count;

    int find(int c)
    {
        if (parent.find(c) == parent.end())
        {
            count++;
            parent[c] = c;
        }
        if (parent[c] == c) 
        {
            return c;
        }
        return parent[c] = find(parent[c]);
    }

    void unite(int r, int c)
    {
        int findR = find(r);
        int findC = find(c);
        if (findR == findC)
        {
            return;
        }
        count--;
        parent[findC] = findR;
    }

    int removeStones(vector<vector<int>>& stones) {
        parent.clear();
        count = 0;
        int n = stones.size();
        for (int i = 0; i < n; i++)
        {
            unite(stones[i][0], stones[i][1] + 20000);
        }
        return n - count;
    }
};
