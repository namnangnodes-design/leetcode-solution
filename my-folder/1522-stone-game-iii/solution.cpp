class Solution {
public:
    vector<int> memo;
    vector<int> mS;
    int mN;
    string stoneGameIII(vector<int>& stoneValue) {
        mN = stoneValue.size();
        mS = stoneValue;
        memo = vector(mN, INT_MIN);
        int res = dp(0);
        if (res > 0)
        {
            return "Alice";
        }
        else if (res < 0)
        {
            return "Bob";
        }
        return "Tie";
    }

    int dp(int i)
    {
        if (i == mN)
        {
            return 0;
        }

        if (memo[i] != INT_MIN)
        {
            return memo[i];
        }

        memo[i] = mS[i] - dp(i + 1);
        if (i < mN - 1)
        {
            memo[i] = max(mS[i] + mS[i + 1] - dp(i + 2), memo[i]);
        }
        if (i < mN - 2)
        {
            memo[i] = max(mS[i] + mS[i + 1] + mS[i + 2] - dp(i + 3), memo[i]);
        }
        return memo[i];
    }
};
