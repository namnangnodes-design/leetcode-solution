class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sumW = 0;
        int maxW = 1;
        for (int i = 0; i < n; i++)
        {
            maxW = max(weights[i], maxW);
            sumW += weights[i];
        }
        int res = sumW;
        int l = maxW;
        int r = sumW;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int cur = 0;
            int day = 0;
            for (int i = 0; i < n; i++)
            {
                if (day == days)
                {
                    break;
                }
                if (cur + weights[i] > m)
                {
                    day++;
                    cur = weights[i];
                }
                else
                {
                    cur += weights[i];
                }
            }
            if (day < days)
            {
                res = min(res, m);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return res;
    }
};
