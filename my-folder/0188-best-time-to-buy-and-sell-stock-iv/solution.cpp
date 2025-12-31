class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int start = 0;
        int end = 0;
        vector<pair<int, int>> trans;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                end = i;
            }
            else
            {
                if (end > start)
                {
                    pair<int, int> newTran = {start, end};
                    trans.push_back(newTran);
                }
                start = i;
            }
        }
        if (end > start)
        {
            pair<int, int> newTran = {start, end};
            trans.push_back(newTran);
        }
        int numOfTrans = trans.size();
        while (numOfTrans > k)
        {
            int minLossDelete = INT_MAX;
            int deleteIdx = -1;
            for (int i = 0; i < trans.size(); i++)
            {
                if (minLossDelete > prices[trans[i].second] - prices[trans[i].first])
                {
                    minLossDelete = prices[trans[i].second] - prices[trans[i].first];
                    deleteIdx = i;
                }
            }
            int minLossMerge = INT_MAX;
            int mergeIdx = -1;
            for (int i = 0; i < trans.size() - 1; i++)
            {
                if (minLossMerge > prices[trans[i].second] - prices[trans[i + 1].first])
                {
                    minLossMerge = prices[trans[i].second] - prices[trans[i + 1].first];
                    mergeIdx = i;
                }
            }
            if (minLossMerge < minLossDelete)
            {
                trans[mergeIdx].second = trans[mergeIdx + 1].second; 
                trans.erase(trans.begin() + mergeIdx + 1);
            }
            else
            {
                trans.erase(trans.begin() + deleteIdx);
            }
            numOfTrans--;
        }
        int profit = 0;
        for (int i = 0; i < trans.size(); i++)
        {
            profit += prices[trans[i].second] - prices[trans[i].first];
        }
        return profit;
    }
};
