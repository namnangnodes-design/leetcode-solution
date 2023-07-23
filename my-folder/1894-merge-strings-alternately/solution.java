class Solution {
    public String mergeAlternately(String word1, String word2) {
		char[] word1Arr = word1.toCharArray();
		char[] word2Arr = word2.toCharArray();
		int word1Len = word1Arr.length;
		int word2Len = word2Arr.length;
		char[]	result = new char[word1Len + word2Len];
		if (word1Len >= word2Len) {
			for (int i = 0; i < word2Len; i++) {
				result[i * 2] = word1Arr[i];
				result[i * 2 + 1] = word2Arr[i];
			}
			for (int i = word2Len * 2; i < word2Len + word1Len; i++) {
				result[i] = word1Arr[i-word2Len];
			}
		} else {
			for (int i = 0; i < word1Len; i++) {
				result[i * 2] = word1Arr[i];
				result[i * 2 + 1] = word2Arr[i];
			}
			for (int i = word1Len*2; i < word1Len + word2Len; i++) {
				result[i] = word2Arr[i-word1Len];
			}
		}
		return String.valueOf(result);
	}
}
