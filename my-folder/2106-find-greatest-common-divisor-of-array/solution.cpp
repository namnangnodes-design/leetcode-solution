class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minV = nums[0];
        int maxV = nums[0];
        for (int num: nums)
        {minV = min(minV, num);
        maxV = max(maxV, num);
        }
        return gcd(minV, maxV);
    }
};
