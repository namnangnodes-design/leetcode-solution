class Solution {
  public String reverseWords(String s) {
		String[] words = s.trim().split(" ");
		StringBuilder result = new StringBuilder();
		for (int i = words.length - 1; i > 0; i--) {
			if (words[i].equals("")) {
				continue;
			}
			result.append(words[i].trim() + " ");
		}
		result.append(words[0]);
		return result.toString();
	}
}
