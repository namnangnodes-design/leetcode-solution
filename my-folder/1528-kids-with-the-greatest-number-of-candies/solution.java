class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
       	List<Boolean> canBeGreatest = new ArrayList<Boolean>(candies.length);
		int max = candies[0];
		for (int i = 1; i < candies.length; i++) {
			if (candies[i] > max) {
				max = candies[i];
			}
		}
		for (int i : candies) {
			if (i + extraCandies >= max) {
				canBeGreatest.add(true);
			} else {
				canBeGreatest.add(false);
			}
		}
		return canBeGreatest;
    }
}
