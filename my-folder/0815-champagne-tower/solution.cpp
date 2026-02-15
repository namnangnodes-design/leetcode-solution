class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cham;
        cham.push_back({(double)poured});
        for (int i = 1; i <= query_row; i++)
        {
            vector<double> cur;
            cur.push_back(max(0.0,(cham[i - 1][0] - 1) / 2.0));
            for (int j = 1; j < i; j++)
            {
                cur.push_back(max(0.0, cham[i - 1][j - 1] - 1) / 2.0 + max(0.0, cham[i - 1][j] - 1) / 2.0);
            }
            cur.push_back(max(0.0, (cham[i - 1][i - 1] - 1) / 2.0));
            cham.push_back(cur);
        }
        return min(1.0, max(0.0, cham[query_row][query_glass]));
    }
};
