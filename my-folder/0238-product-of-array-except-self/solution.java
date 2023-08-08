class Solution {
    public int[] productExceptSelf(int[] nums) {
		int zeroCount = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == 0) {
				if (++zeroCount == 2) {
					break;
				}
			}
		}
		if (zeroCount == 2) {
			nums = new int[nums.length];
		} else if (zeroCount == 1) {
			int product = 1;
			for (int i = 0; i < nums.length; i++) {
				if (nums[i] == 0) {
					continue;
				}
				product *= nums[i];
			}
			for (int i = 0; i < nums.length; i++) {
				if (nums[i] == 0) {
					nums[i] = product;
					continue;
				}
				nums[i] = 0;
			}
		} else {
			int product = 1;
			for (int i = 0; i < nums.length; i++) {
				product *= nums[i];
			}
			for (int i = 0; i < nums.length; i++) {
				nums[i] = product / nums[i];
			}
		}
		return nums;
	}
}
