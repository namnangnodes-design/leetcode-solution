class Solution {
    public int[] plusOne(int[] digits) {
        boolean fullNine = true;
		int lastNine = digits.length - 1;
		for (int i = digits.length - 1; i >= 0; i--) {
			if (digits[i] != 9) {
				fullNine = false;
				lastNine = i;
				break;
			}
		}
		if (fullNine) {
			digits = new int[digits.length + 1];
			digits[0] = 1;
			return digits;
		}
		for (int i = digits.length - 1; i > lastNine; i--) {
			digits[i] = 0;
		}
		digits[lastNine]++;
		return digits;
    }
}
