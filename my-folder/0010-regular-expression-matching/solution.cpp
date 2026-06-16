class Solution {
public:
    vector<vector<int>> memo;
    string mS, mP;
    int mM, mN;

    bool isMatch(string s, string p) {
        mS = s;
        mP = p;
        mM = s.length();
        mN = p.length();
        memo = vector<vector<int>>(mM + 1, vector<int>(mN + 1, -1));
        return dp(0, 0);
    }

    int dp(int i, int j)
    {
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (j == mN)
        {
            return memo[i][j] = i == mM;
        }

        bool isFirstMatch = i < mM && (mS[i] == mP[j] || mP[j] == '.');
        bool ans = false;
        if (j + 1 < mN && mP[j + 1] == '*')
        {
            ans = dp(i, j + 2) || (isFirstMatch && dp(i + 1, j));
        }
        else
        {
            ans = isFirstMatch && dp(i + 1, j + 1);
        }

        return memo[i][j] = ans;
    }
};
