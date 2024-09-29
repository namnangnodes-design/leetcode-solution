class Solution {
public:
    vector<int> DP;
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2)
        {
            return min(cost[0], cost[1]);
        }
        int lastStair = cost.size() - 1;
        DP.clear();
        DP.push_back(cost[0]);
        DP.push_back(cost[1]);
        for (int i = 2; i <= lastStair; i++)
        {
            int minChoose = min(DP[i - 1] + cost[i], DP[i - 2] + cost[i]);
            DP.push_back(minChoose);
        }
        return min(DP[lastStair - 1], DP[lastStair]);
    }
};
