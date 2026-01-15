class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hx = 0;
        int hy = 0;
        int maxH = 0;
        int maxV = 0;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] - 1 == hBars[i - 1])
            {
                hy = i;
                if (maxH < hy - hx) maxH = hy - hx;
            }
            else
            {
                hx = i;
                hy = i;
            }
        }
        hx = 0;
        hy = 0;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] - 1 == vBars[i - 1])
            {
                hy = i;
                if (maxV < hy - hx) maxV = hy - hx;
            }
            else
            {
                hx = i;
                hy = i;
            }
        }
        return min(maxV + 2, maxH + 2) * min(maxV + 2, maxH + 2);
    }
};
