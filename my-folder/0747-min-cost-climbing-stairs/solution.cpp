class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last = cost.size();
        vector<int> DP(last + 1);
        DP[0] = 0; DP[1] = 0;
        for (int i = 2; i < last + 1; i++)
        {
            DP[i] = min(DP[i - 2] + cost[i - 2], DP[i - 1] + cost[i - 1]);
        }
        return DP[last];
    }
};
