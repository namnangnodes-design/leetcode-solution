class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> map;
        long long result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i] - palindrone(nums[i]);
            result += map[temp];
            map[temp] = map[temp] + 1;
        }
        return result % static_cast<int>(pow(10, 9) + 7);
    }

    int palindrone(int x)
    {
        int reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return reverse;
    }
};
