class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int left = 0;
        int right = n - 1;
        int mid = left + (right - left) / 2;
        while (left <= right)
        {
            if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
                mid = left + (right - left) / 2;
                continue;
            }
            if (mid == n - 1)
            {
                if (nums[mid] > nums[mid - 1])
                {
                    return mid;
                }
                else
                {
                    right = mid - 1;
                }
                mid = left + (right - left) / 2;
                continue;
            }
            //printf("if %d mid = %d \n", 1, mid);
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            //printf("if %d mid = %d \n", 2, mid);
            if (nums[mid] < nums[mid - 1])
            {
                right = mid - 1;
            } 
            else if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            } 
            mid = left + (right - left) / 2;
        }
        return 0;
    }
};
