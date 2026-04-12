class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;

        int minNum = nums[0], maxNum = nums[0];
        for (int x : nums) {
            minNum = min(minNum, x);
            maxNum = max(maxNum, x);
        }

        int offset = minNum; 
        for (int i = 0; i < n; i++) {
            nums[i] -= offset; 
        }
        maxNum -= offset;

        vector<int> res(n);
        for (long long exp = 1; maxNum / exp > 0; exp *= 10) {
            vector<int> count(10, 0);
            
            for (int j = 0; j < n; j++) {
                count[(nums[j] / exp) % 10]++;
            }
            
            for (int j = 1; j < 10; j++) {
                count[j] += count[j - 1];
            }
            
            for (int j = n - 1; j >= 0; j--) {
                int digit = (nums[j] / exp) % 10;
                res[count[digit] - 1] = nums[j];
                count[digit]--;
            }
            
            nums = res; 
        }

        for (int i = 0; i < n; i++) {
            nums[i] += offset;
        }

        return nums;
    }
};
