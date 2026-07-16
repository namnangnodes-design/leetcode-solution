class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long mxi = nums[0];
        int n = nums.size();
        vector<long long> prefixGcd;
        for (int i = 0; i < n; i++)
        {
            mxi = max((long long)nums[i], mxi);
            prefixGcd.push_back(gcd(mxi, nums[i]));
        }
        sort(prefixGcd.begin(), prefixGcd.end(), greater<long long>());
        long long res = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            res += gcd(prefixGcd[i], prefixGcd[j]);
        }

        return res;
    }
};
