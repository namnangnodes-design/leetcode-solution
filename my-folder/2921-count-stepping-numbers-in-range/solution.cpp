class Solution {
public:
    const int MOD = 1e9 + 7; 
    string num;
    int memo[101][10][2][2];


    int countSteppingNumbers(string low, string high) {
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                memo[i][j][0][0] = -1;
                memo[i][j][0][1] = -1;
                memo[i][j][1][0] = -1;
                memo[i][j][1][1] = -1;
            }
        }
        //printf("low \n");
        num = low;
        int l = dp(0, 0, true, false);
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                memo[i][j][0][0] = -1;
                memo[i][j][0][1] = -1;
                memo[i][j][1][0] = -1;
                memo[i][j][1][1] = -1;
            }
        }
        //printf("high \n");
        num = high;
        int h = dp(0, 0, true, false);
        bool isStep = true;
        for (int i = 1; i < low.size(); i++)
        {
            if (abs(low[i] - low[i - 1]) != 1)
            {
                isStep = false;
                break;
            }
        } 
        return (h - l + isStep + MOD) % MOD;
    }

    int dp(int i, int pre, int tight, int started)
    {
        if (i == num.length())
        {
            //printf("%d %d \n", i, pre);
            return started ? 1 : 0;
        }

        if (memo[i][pre][tight][started] != -1)
        {
            return memo[i][pre][tight][started];
        }

        int limit = tight ? (num[i] - '0') : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++)
        {
            bool nextTight = tight && (d == limit);
            if (!started)
            {
                if (d == 0)
                {
                    ans = (ans + dp(i + 1, 0, nextTight, false)) % MOD;
                }
                else
                {
                    ans = (ans + dp(i + 1, d, nextTight, true)) % MOD;
                }
            }
            else
            {
                if (abs(d - pre) == 1)
                {
                    ans = (ans + dp(i + 1, d, nextTight, true)) % MOD;
                }
            }
        }

        return memo[i][pre][tight][started] = ans;
    }
};
