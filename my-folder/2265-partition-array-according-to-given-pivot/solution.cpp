class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        int pCount = 0;
        vector<int> right;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                left.push_back(nums[i]);
            }
            else if (nums[i] == pivot)
            {
                pCount++;
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        for (int i = 0; i < pCount; i++)
        {
            left.push_back(pivot);
        }
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
