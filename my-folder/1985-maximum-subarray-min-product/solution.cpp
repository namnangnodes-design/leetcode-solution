class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            prefix[i] = (i == 0 ? 0 : prefix[i - 1]) + nums[i];
            while (!s.empty() && nums[i] < nums[s.top()])
            {
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop(); 
        for (int i = n - 1; i > -1; i--)
        {
            while (!s.empty() && nums[i] < nums[s.top()])
            {
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, nums[i] * (prefix[right[i] - 1] - (left[i] == -1 ? 0 : prefix[left[i]]))); 
        }
        return res % 1000000007;
    }
};
