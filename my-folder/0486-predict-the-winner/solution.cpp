class Solution {
public:
    vector<vector<int>> memo;
    vector<int> mN;

    bool predictTheWinner(vector<int>& nums) {
        mN = nums;
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INT_MIN));
        return maxDiff(0, nums.size() - 1) >= 0;
    }

    int maxDiff(int l, int r)
    {
        if (l == r)
        {
            return mN[l];
        }

        if (memo[l][r] != INT_MIN)
        {
            return memo[l][r];
        }

        return memo[l][r] = max((mN[l] - maxDiff(l + 1, r)), (mN[r] - maxDiff(l, r - 1)));
    }
};
