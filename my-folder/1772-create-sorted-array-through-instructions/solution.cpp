class Solution {
public:
    vector<int> st;
    int MOD = 1000000007;
    void update(int i, int l, int r, int p)
    {
        if (l == r)
        {
            st[i]++;
            return;
        }

        int m = l + (r - l) / 2;

        if (p <= m)
        {
            update(i * 2 + 1, l, m, p);
        }
        else
        {
            update(i * 2 + 2, m + 1, r, p);
        }

        st[i] = st[i * 2 + 1] + st[i * 2 + 2];
    }

    int query(int i, int l, int r, int u, int v)
    {
        if (v < l || u > r)
        {
            return 0;
        }

        if (u <= l && v >= r)
        {
            return st[i];
        }

        int m = l + (r - l) / 2;
        int left = query(i * 2 + 1, l, m, u, v);
        int right = query(i * 2 + 2, m + 1, r, u, v);
        return left + right;
    }

    int createSortedArray(vector<int>& instructions) {
        st = vector<int>(400005, 0);
        int res = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            res = (res + min(query(0, 0, 1e5, 0, instructions[i] - 1), query(0, 0, 1e5, instructions[i] + 1, 1e5))) % MOD;
            update(0, 0, 1e5, instructions[i]);
        }
        return res;
    }
};
