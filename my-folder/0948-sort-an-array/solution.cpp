class Solution {
public:
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }

    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        int l = left, r = mid + 1, k = left;

        while (l <= mid && r <= right) {
            if (nums[l] <= nums[r]) {
                temp[k++] = nums[l++];
            } else {
                temp[k++] = nums[r++];
            }
        }
        while (l <= mid) temp[k++] = nums[l++];
        while (r <= right) temp[k++] = nums[r++];

        // Copy sorted elements back to original array
        std::copy(temp.begin() + left, temp.begin() + right + 1, nums.begin() + left);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());  // Preallocate temp buffer
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};

