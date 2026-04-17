class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> res = prices;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty())
            {
                int l = s.top();
                if (prices[l] >= prices[i])
                {
                    res[l] = prices[l] - prices[i];
                    s.pop(); 
                }
                else
                {
                    break;
                }
            }
            s.push(i);
        }

        return res;
        
    }
};
