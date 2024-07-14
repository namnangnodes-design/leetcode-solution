class RecentCounter {
public:
    queue<int> mQueue;
    RecentCounter() {
        
    }

    int ping(int t) {
        mQueue.push(t);
        int lower = t - 3000;
        while (!mQueue.empty() && mQueue.front() < lower)
        {
            mQueue.pop();
        }
        return mQueue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
