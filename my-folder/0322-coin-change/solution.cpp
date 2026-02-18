class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> coin;
        vector<bool> visited(amount, false);
        coin.push(0);
        visited[0] = true;
        int step = 0;
        int m = coins.size();
        while (!coin.empty())
        {
            int q = coin.size();
            for (int i = 0; i < q; i++)
            {
                int cur = coin.front();
                coin.pop();
                for (int j = 0; j < m; j++)
                {
                    int next = cur + coins[j];
                    if (next == amount) return ++step;
                    if ( next <= amount && !visited[next])
                    {
                        coin.push(next);
                        visited[next] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
