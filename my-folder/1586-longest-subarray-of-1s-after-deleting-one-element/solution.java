class Solution {
    public int longestSubarray(int[] nums) {
        int max = 0;
		int first = 0;
		int second = 0;
		boolean deleted = false;
		for (int i = 0; i < nums.length; i++) {
			if (!deleted) {
				if (nums[i] == 1) {
					first++;
					max = Math.max(first + second, max);
				} else {
					deleted = true;
				}
			} else {
				if (nums[i] == 1) {
					second++;
					max = Math.max(first + second, max);
				} else {
					first = second;
					second = 0;
				}
			}
		}
		return deleted == true ? max : (max - 1);
    }
}
