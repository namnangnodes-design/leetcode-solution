class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            while (s.size() != 0)
            {
                int l = s.back();
                if (heights[l] >= heights[i])
                {
                    s.pop_back();
                }
                else
                {
                    break;
                }
            }
            s.push_back(i);
            int m = s.size();
            for (int j = 0; j < m; j++)
            {
                if (j == 0) 
                {
                    res = max(res, (i + 1) * heights[s[j]]);
                    continue;
                }
                if (m > 2 && j == m - 1)
                {
                    res = max(res, (i - s[j - 2]) * heights[s[j - 1]]);
                }
                res = max(res, (i - s[j - 1]) * heights[s[j]]);
            }
        }
        return res;
    }
};
