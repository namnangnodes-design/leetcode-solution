class NumArray {
public:
    vector<int> st;
    vector<int> s;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        st.clear();
        st = vector<int>(4 * n);
        s = nums;
        build(0, 0, nums.size() - 1);
    }

    void build(int i, int l, int r)
    {
        if (l == r)
        {
            st[i] = s[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m + 1, r);
        st[i] = st[i * 2 + 1] + st[i * 2 + 2];
    }
    
    void update(int index, int val) {
        change(0, 0, s.size() - 1, index, val);
    }

    void change(int i, int l, int r, int pos, int v)
    {
        if (l == r)
        {
            s[pos] = v;
            st[i] = v;
            return;
        }

        int m = l + (r - l) / 2;
        if (pos <= m)
        {
            change(i * 2 + 1, l, m, pos, v);
        }
        else
        {
            change(i * 2 + 2, m + 1, r, pos, v);
        }

        st[i] = st[i * 2 + 1] + st[i * 2 + 2];
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, s.size() - 1, left, right);
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
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
