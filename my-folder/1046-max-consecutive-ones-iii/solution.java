class Solution {
    public int longestOnes(int[] nums, int k) {
		int len = 0;
		int start = 0;
		int max = 0;
		if (k == 0) {
			for (int i = 0; i < nums.length; i++) {
				if (nums[i] == 0) {
					len = 0;
				} else {
					if (++len > max) {
						max = len;
					}
				}
			}
			return max;
		}
		int flip = k;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == 0) {
				if (flip == 0) {
					int j;
					for (j = start; j < i; j++) {
						len--;
						if (nums[j] == 0) {
							flip++;
							start = j + 1;
							break;
						}
					}
					if (flip == 0) {
						flip = 1;
						len = 0;
						start = i + 1;
						continue;
					}
				}
				flip--;
			}
			if (++len > max) {
				max = len;
			}
		}
		return max;
    }
}
