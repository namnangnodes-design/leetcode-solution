class Solution {
public:
    vector<int> st;

    void change(int i, int l, int r, int pos)
    {
        if (l == r)
        {
            st[i]++;
            return;
        }

        int m = l + (r - l) / 2;
        if (pos <= m)
        {
            change(i * 2 + 1, l, m, pos);
        }
        else
        {
            change(i * 2 + 2, m + 1, r, pos);
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
        int lSum = query(i * 2 + 1, l, m, u, v);
        int rSum = query(i * 2 + 2, m + 1, r, u, v);
        return lSum + rSum;
    }

    int createSortedArray(vector<int>& instructions) {
        st = vector<int>(400005, 0);
        long long res = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            res = (res + min(query(0, 0, 1e5, 0, instructions[i] - 1), query(0, 0, 1e5, instructions[i] + 1, 1e5))) % (1000000007);
            change(0, 0, 1e5, instructions[i]);
        }

        return res;
    }
};
