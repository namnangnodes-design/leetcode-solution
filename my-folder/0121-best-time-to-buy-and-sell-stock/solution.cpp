class Solution {
public:
    vector<int> changes;
    int findMaxCrossingSubArray(int low, int mid, int high)
    {
        int leftSum = -20000;
        int rightSum = -20000;
        int temp = 0;
        for (int i = mid; i >= low; i--)
        {
            temp += changes[i];
            if (temp > leftSum)
            {
                leftSum = temp;
            }
        }
        temp = 0;
        for (int i = mid + 1; i <= high; i++)
        {
            temp += changes[i];
            if (temp > rightSum)
            {
                rightSum = temp;
            }
        }
        return leftSum + rightSum;
    }
    int findMaximumSubArray(int low, int high)
    {
        if (high == low)
        {
            return changes[low];
        }
        int mid = (low + high) / 2;
        int leftSum = findMaximumSubArray(low, mid);
        int rightSum = findMaximumSubArray(mid + 1, high);
        int crossSum = findMaxCrossingSubArray(low, mid, high);
        if (leftSum >= rightSum && leftSum >= crossSum)
        {
            return leftSum;
        }
        else if (rightSum >= crossSum && rightSum >= leftSum)
        {
            return rightSum;
        }
        else
        {
            return crossSum;
        }
    }
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        changes.clear();
        for (int i = 0; i < prices.size() - 1; i++)
        {
            changes.push_back(prices[i + 1] - prices[i]);
        }
        int result = findMaximumSubArray(0, changes.size() - 1);
        return result < 0 ? 0 : result;
    }
};
