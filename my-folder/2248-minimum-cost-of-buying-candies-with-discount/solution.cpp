class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += cost[i];
            if (i < n - 1)
            {
                res += cost[i + 1];
            }
            i += 2;
        }
        return res;
    }
};
