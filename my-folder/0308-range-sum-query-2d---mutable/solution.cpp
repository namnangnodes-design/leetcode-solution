class NumMatrix {
public:
    vector<vector<int>> s;
    vector<vector<int>> st;
    int mM;
    int mN;

    NumMatrix(vector<vector<int>>& matrix) {
        mM = matrix.size();
        mN = matrix[0].size();
        s = matrix;
        st = vector<vector<int>> (mM, vector<int>(mN * 4, 0));
        for (int i = 0; i < mM; i++)
        {
            build(i, 0, 0, mN - 1);
        }
    }

    void build(int row, int i, int l, int r)
    {
        if (l == r)
        {
            st[row][i] = s[row][l];
            return;
        }

        int m = l + (r - l) / 2;
        build(row, i * 2 + 1, l, m);
        build(row, i * 2 + 2, m + 1, r);
        st[row][i] = st[row][i * 2 + 1] + st[row][i * 2 + 2];
    }

    void change(int row, int i, int l, int r, int pos, int v)
    {
        if (l == r)
        {
            st[row][i] = v;
            s[row][pos] = v;
            return;
        }

        int m = l + (r - l) / 2;
        if (pos <= m)
        {
            change(row, i * 2 + 1, l, m, pos, v);
        }
        else
        {
            change(row, i * 2 + 2, m + 1, r, pos, v);
        }
        st[row][i] = st[row][i * 2 + 1] + st[row][i * 2 + 2];
    }
    
    void update(int row, int col, int val) {
        change(row, 0, 0, mN - 1, col, val);
    }
    
    int query(int row, int i, int l, int r, int u, int v)
    {
        if (r < u || l > v)
        {
            return 0;
        }

        if (u <= l && v >= r)
        {
            return st[row][i];
        }

        int m = l + (r - l) / 2;
        int left = query(row, i * 2 + 1, l, m, u, v);
        int right = query(row, i * 2 + 2, m + 1, r, u, v);
        return left + right;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; i++)
        {
            res += query(i, 0, 0, mN - 1, col1, col2);
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
