class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var map = HashMap<Int, Int>()
        var result = IntArray(2)
        for (i in nums.indices) {
            val complement = target - nums[i]
            if (map.containsKey(complement)) {
                result[0] = map[complement]!!
                result[1] = i
                return result
            }
            else
            {
                map.put(nums[i], i);
            }
        }
        return result
    }
}
