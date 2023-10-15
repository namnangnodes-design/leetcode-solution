class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
		HashSet<Integer> nums = new HashSet<>();
		HashSet<Integer> dis = new HashSet<>();
		for (int i = 0; i < nums1.length; i++) {
			nums.add(nums1[i]);
		}
		for (int i = 0; i < nums2.length; i++) {
			dis.add(nums2[i]);
		}
		answer.add(new ArrayList<>());
		answer.add(new ArrayList<>());
		for (int i : nums) {
            if (!dis.contains(i)) {
			    answer.get(0).add(i);
            }
		}
		for (int i : dis) {
            if (!nums.contains(i)) {
			    answer.get(1).add(i);
            }
		}
		return answer;
    }
}
