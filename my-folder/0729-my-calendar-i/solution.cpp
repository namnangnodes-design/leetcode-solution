class MyCalendar {
    map<int, int>timeBook;
public:
    bool book(int startTime, int endTime) {
        auto it = timeBook.lower_bound(startTime);
        if (it!= timeBook.end() && it->first < endTime) return false;
        if (it!= timeBook.begin() && (--it)->second > startTime) return false;
        timeBook[startTime] = endTime;
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
