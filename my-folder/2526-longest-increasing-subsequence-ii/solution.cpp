class Solution {
public:
    vector<int> st;
    int mDiff;

    void update(int i, int l, int r, int p, int v)
    {
        if (l == r)
        {
            st[i] = max(st[i], v);
            return;
        }

        int m = l + (r - l) / 2;
        if (p <= m)
        {
            update(i * 2 + 1, l, m, p, v);
        }
        else
        {
            update(i * 2 + 2, m + 1, r, p, v);
        }

        st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
    }

    int query(int i, int l, int r, int u, int v)
    {
        if (v < l || u > r)
        {
            return 0;
        }

        if (u <= l && r <= v)
        {
            return st[i];
        }

        int m = l + (r - l) / 2;
        int left = query(i * 2 + 1, l, m, u, v);
        int right = query(i * 2 + 2, m + 1, r, u, v);
        return max(left, right);
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int ans = 0;
        st.clear();
        st = vector<int>(4 * maxVal, 0);
        
        for (int num: nums)
        {
            int left = max(1, num - k);
            int right = num - 1;

            int cur = 0;
            if (left <= right)
            {
                cur = query(0, 0, maxVal, left, right);
            }

            cur++;
            ans = max(ans, cur);
            update(0, 0, maxVal, num, cur);

        }

        return ans;
    }
};
