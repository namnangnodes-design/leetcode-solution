class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int res = 0;
        int val = tickets[k];
        for (int i = 0; i <= k; i++)
        {
            res += min(val, tickets[i]);
        }
        for (int i = k + 1; i < n; i++)
        {
            res += min(val - 1, tickets[i]);
        }
        return res;
    }
};
