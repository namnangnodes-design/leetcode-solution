class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> s;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = n - 1; i > -1; i--)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            s.pop();
        }
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int res = nums[k];
        for (int i = 0; i < n; i++)
        {
            if (k > left[i] && k < right[i]) res = max(res, nums[i] * (right[i] - 1 - left[i] - 1 + 1));
        }
        return res;
    }
};
