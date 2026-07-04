class Solution {
public:
    string t;
    string w1;
    string w2;
    int MOD = 1000000007;
    int memo[101][101][101];
    int interleaveCharacters(string word1, string word2, string target) {
        t = target;
        w1 = word1;
        w2 = word2;
        for (int i = 0; i < 101; i++)
            {
                for (int j = 0; j < 101; j++)
                    {
                        for (int k = 0; k < 101; k++)
                            {
                                memo[i][j][k] = -1;
                            }
                    }
            }
        return dp(0, 0, 0);
    }

    int dp(int i0, int i1, int i2)
    {
        if (i0 == t.size())
        {
            if (i1 != 0 && i2 != 0) return 1;
            return 0;
        }

        if (memo[i0][i1][i2] != -1)
        {
            return memo[i0][i1][i2];
        }

        long res = 0;
        for (int i = i1; i < w1.size(); i++)
            {
                if (t[i0] == w1[i])
                {
                    res = (res + dp(i0 + 1, i + 1, i2)) % MOD;
                }
            }

                for (int i = i2; i < w2.size(); i++)
            {
                if (t[i0] == w2[i])
                {
                    res = (res + dp(i0 + 1, i1, i + 1)) % MOD;
                }
            }

        return memo[i0][i1][i2] = res;
    }
};
