import java.util.Hashtable;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
       Hashtable<Integer, Integer> great = new Hashtable<Integer, Integer>();
		for (int i = 0; i < nums2.length; i++) {
			boolean found = false;
            System.out.println(nums2[i]);
			for (int j = i + 1; j < nums2.length; j++) {
				if (nums2[j] > nums2[i]) {
					great.put(nums2[i], nums2[j]);
					found = true;
					break;
				}
			}
			if (!found) {
				great.put(nums2[i], -1);
			}
		}
		int[] ans = new int[nums1.length];
		for (int i = 0; i < nums1.length; i++) {
			ans[i] = great.get(nums1[i]);
		}
		return ans;
    }
}
