class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {nums[0] * nums[0]};
        vector<int> res;
        if (nums[0] >= 0)
        {
            for (int i = 0; i < n; i++)
            {
                res.push_back(nums[i] * nums[i]);
            }
        }
        else if (nums[n - 1] <= 0)
        {
            for (int i = n - 1; i > -1; i--)
            {
                res.push_back(nums[i] * nums[i]);
            }
        }
        else
        {
            int neg = 0;
            int pos = 0;
            for (int i = 1; i < n; i++)
            {
                if (nums[i - 1] < 0  && nums[i] >= 0)
                {
                    neg = i - 1;
                    pos = i;
                }
            }
            int sqPos = nums[pos] * nums[pos];
            int sqNeg = nums[neg] * nums[neg];
            while (pos < n && neg > -1)
            {
                if (sqPos <= sqNeg)
                {
                    res.push_back(sqPos);
                    pos++;
                    if (pos < n) sqPos = nums[pos] * nums[pos];
                }
                else
                {
                    res.push_back(sqNeg);
                    neg--;
                    if (neg > -1) sqNeg = nums[neg] * nums[neg];
                }
            }
            while (neg > -1)
            {
                res.push_back(sqNeg);
                neg--;
                if (neg > -1) sqNeg = nums[neg] * nums[neg];
            }
            while (pos < n)
            {
                res.push_back(sqPos);
                pos++;
                if (pos < n) sqPos = nums[pos] * nums[pos];                
            }
        }

        return res;
    }
};
