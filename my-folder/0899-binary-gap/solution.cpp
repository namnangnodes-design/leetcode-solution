class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int cur = -1;
        int step = 0;
        int res = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                if (cur != -1)
                {
                    prev = cur;
                    cur = step + 1;
                    res = max(res, cur - prev);
                }
                else cur = step + 1;
            }
            n /= 2;
            step++;
        }
        return res;
    }
};
