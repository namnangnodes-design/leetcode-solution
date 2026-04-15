class Solution {
public:
    static bool mCompare(vector<int> a, vector<int> b)
    {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), mCompare);
        for (int i = 0; i < k; i++)
        {
            res.push_back(points[i]);
        }
        return res;
    }
};
