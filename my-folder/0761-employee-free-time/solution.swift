/**
 * Definition for an Interval.
 * public class Interval {
 *     public var start: Int
 *     public var end: Int
 *     public init(_ start: Int, _ end: Int) {
 *         self.start = start
 *         self.end = end
 *     }
 * }
 */

class LCInterval: Interval, Comparable { 
    var employeeNum: Int 

    public init(_ interval: Interval,_ employeeNum: Int) {
        self.employeeNum = employeeNum
        super.init(interval.start, interval.end)
    }

    static public func < (_ lhs: LCInterval, _ rhs: LCInterval) -> Bool { 
        if lhs.start == rhs.start { return lhs.end < rhs.end }
        return lhs.start < rhs.start
    }

 }

class Solution {
    func employeeFreeTime(_ schedule: [[Interval]]) -> [Interval] {

        var heap = Heap<LCInterval>()
        for (idx, employee) in schedule.enumerated() { 
            guard var firstInterval = employee.first else { continue }
            heap.insert(LCInterval(firstInterval, idx))
        }

        let intervalsStart = heap.min!.start
        var curEnd = intervalsStart
        //Keeps track of the current index in each array
        var employeeCounts = Array(repeating: 1, count: schedule.count)
        var ans = [Interval]()
        while let cur = heap.popMin() {
            if cur.start > curEnd { 
                ans.append(Interval(curEnd, cur.start))
            }

            curEnd = max(curEnd, cur.end)

            //Add next interval from employee schedule if we haven't reached the end of the array
            let employeeNum = cur.employeeNum, idx = employeeCounts[employeeNum]
            if idx < schedule[employeeNum].count { 
                var next = LCInterval(schedule[employeeNum][idx], employeeNum)
                employeeCounts[cur.employeeNum] += 1 
                heap.insert(next)
            }
        }

        return ans
    }
}
