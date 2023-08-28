class Solution {
   public static int compress(char[] chars) {
		int index = 0;
		int count = 1;
		chars[index] = chars[0];
		++index;
		for (int i = 1; i < chars.length; i++) {
			if (chars[i] == chars[index - 1]) {
				count++;
			} else if (count != 1) {
				if (count < 10) {
					chars[index] = (char) ('0' + count);
					++index;
				} else {
					char[] num = Integer.toString(count).toCharArray();
					for (int j = 0; j < num.length; j++) {
						chars[index] = num[j];
						++index;
					}
				}
				count = 1;
				chars[index] = chars[i];
				++index;
			} else {
				chars[index] = chars[i];
				++index;
			}
		}
		if (count != 1) {
			if (count < 10) {
				chars[index] = (char) ('0' + count);
				++index;
			} else {
				char[] num = Integer.toString(count).toCharArray();
				for (int j = 0; j < num.length; j++) {
					chars[index] = num[j];
					++index;
				}
			}
		}
		return index;
	}
}
