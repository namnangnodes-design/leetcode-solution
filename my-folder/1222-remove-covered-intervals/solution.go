import "sort"

func removeCoveredIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})

	ans := len(intervals)
	maxEnd := 0

	for _, cur := range intervals {
		if cur[1] <= maxEnd {
			ans--
		} else {
			maxEnd = cur[1]
		}
	}

	return ans
}
