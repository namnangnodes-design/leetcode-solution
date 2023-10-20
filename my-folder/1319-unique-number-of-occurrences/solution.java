class Solution {
    public boolean uniqueOccurrences(int[] arr) {
		HashMap<Integer, Integer> countMap = new HashMap<>();
		for (int i = 0; i < arr.length; i++) {
			if (!countMap.containsKey(arr[i])) {
				countMap.put(arr[i], 1);
			} else {
				countMap.put(arr[i], countMap.get(arr[i]) + 1);
			}
		}
		HashSet<Integer> countSet = new HashSet<>();
		countSet.addAll(countMap.values());
		if (countSet.size() == countMap.size()) {
			return true;
		}
		return false;
	}
}
