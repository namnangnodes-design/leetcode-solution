class Solution {
    public int searchInsert(int[] nums, int target) {
        if (nums.length == 1) {
			return (nums[0] >= target ? 0 : 1);
		}
		int left = 0;
		int right = nums.length - 1;
		int mid = 1;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else {
                right = mid - 1;
			}
		}
		return right + 1;
    }
}
