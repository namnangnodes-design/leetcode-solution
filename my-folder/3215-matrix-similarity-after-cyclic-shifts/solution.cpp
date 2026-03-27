class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        int can = true;
        for (int i = 0; i < m; i++)
        {
            if (!can) break;
            for (int j = 0; j < n; j++)
            {
                if ((i % 2 == 0 && mat[i][j] != mat[i][(j + n - k) % n]) || (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]))
                {
                    can = false;
                    break;
                }
            }
        }
        return can;
    }
};
