class Solution {
    public int maxOperations(int[] nums, int k) {
      HashMap<Integer, Integer> numMap = new HashMap<>();
		HashSet<Integer> setSet = new HashSet<>();
		int count = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] >= k) {
				continue;
			}
			if (!numMap.containsKey(nums[i])) {
				numMap.put(nums[i], 1);
			} else {
				numMap.put(nums[i], numMap.get(nums[i]) + 1);
			}
		}
		for (int i : numMap.keySet()) {
			if (setSet.contains(i)) {
				continue;
			}
			setSet.add(i);
			if (i == k - i) {
				count += numMap.get(i) / 2;
			} else if (numMap.containsKey(k - i)) {
				setSet.add(k - i);
				count += Math.min(numMap.get(i), numMap.get(k - i));
			}
		}
		return count;
    }
}
