class MyCalendarThree {
public:
    std::map<int, int> intervals;

    MyCalendarThree() {
        intervals.clear();
    }
    
    int book(int startTime, int endTime) {
        intervals[startTime]++;
        intervals[endTime]--;
        int maxVal = 0;
        int cur = 0;
        for (auto &i: intervals)
        {
            cur += i.second;
            maxVal = max(cur, maxVal);
        }
        return maxVal;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
