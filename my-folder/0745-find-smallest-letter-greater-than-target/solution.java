class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0;
		int right = letters.length - 1;
		int mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (letters[mid] == target) {
				for (int i = mid; i < letters.length; i++) {
					if (letters[i] != target) {
						return letters[i];
					}
				}
				return letters[0];
			} else if (letters[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
        if (left > letters.length - 1) {
			return letters[0];
		}
		return letters[left] > target ? letters[left] : letters[0];
    }
}
