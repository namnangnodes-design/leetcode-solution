class Solution {
public:
    bool mRes;
    const double EPSILON = 1e-6;

    bool judgePoint24(vector<int>& cards) {
        mRes = false;
        vector<double> cal;
        for (int card: cards)
        {
            cal.push_back((double) card);
        }
        backtrack(cal);
        return mRes;
    }

    void backtrack(vector<double> nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            if (abs(nums[0] - 24) < EPSILON)
            {
                mRes = true;
            }
            return;
        }
        vector<double> temp = nums;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                double a = nums[i];
                double b = nums[j];
                if (i > j)
                {
                    nums.erase(nums.begin() + i);
                    nums.erase(nums.begin() + j);
                }
                else
                {
                    nums.erase(nums.begin() + j);
                    nums.erase(nums.begin() + i);                    
                }
                nums.push_back((double)a + b);
                backtrack(nums);
                nums.pop_back();
                nums.push_back((double)a - b);
                backtrack(nums);
                nums.pop_back();
                nums.push_back((double)a * b);
                backtrack(nums);
                nums.pop_back();
                if (b != 0.0)
                {
                    nums.push_back((double)a / b);
                    backtrack(nums);
                    nums.pop_back();
                }
                nums = temp;
            }
        }
    }
};
