class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        map<int, long long> v;
        for (int i = 0; i < costs.size(); i++)
        {
            v[costs[i]]++;
        }
        for (int i = 0; i <= 1e5; i++)
        {
            if (coins >= i * v[i])
            {
                coins -= i * v[i];
                res += v[i];
            }
            else
            {
                res += coins / i;
                break;
            }
        }
        return res;
    }
};
