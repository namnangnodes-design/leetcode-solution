class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        long long maxDiff = LLONG_MIN; 
        long long maxMinus = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            maxDiff = max(maxDiff, maxMinus - (long long) nums[i]);
            maxMinus = max(maxMinus, (long long) nums[i]);
            result = max(result, maxDiff * (long long) nums[i + 1]);
        }
        return result;
    }
};
