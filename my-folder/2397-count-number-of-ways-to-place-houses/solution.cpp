class Solution {
public:
    long long mPush[10001];

    int countHousePlacements(int n) {
        long long p = backtrack(n);
        return p * p % 1000000007;
    }

    long long backtrack(int i)
    {
        if (mPush[i] != 0) return mPush[i];
        if (i == 0)
        {
            mPush[0] = 1;
            return 1;
        }
        if (i == 1)
        {
            mPush[1] = 2;
            return 2;
        }
        mPush[i] = (backtrack(i - 1) + backtrack(i - 2)) % 1000000007;
        return mPush[i];
    }
};
