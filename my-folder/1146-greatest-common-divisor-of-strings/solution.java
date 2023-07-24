class Solution {
    public String gcdOfStrings(String str1, String str2) {
        	ArrayList<Integer> commonDivisor = new ArrayList<Integer>();
		int a = str1.length();
		int b = str2.length();
		for (int i = Math.min(a, b); i >= 1; i--) {
			if (a % i == 0 && b % i == 0) {
				commonDivisor.add(i);
			}
		}
		String temp;
		for (int i : commonDivisor) {
			temp = str1.substring(0, i);
			boolean divisble = true;
			for (int j = 0; j <= a - i; j += i) {
				if (!str1.substring(j, j + i).equals(temp)) {
					divisble = false;
					break;
				}
			}
			if (!divisble) {
				continue;
			}
			for (int j = 0; j <= b - i; j += i) {
				if (!str2.substring(j, j + i).equals(temp)) {
					divisble = false;
					break;
				}
			}
			if (divisble) {
				return temp;
			}
		}
		return "";
    }
}
