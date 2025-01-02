class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int> > mQueue;
    int smallest = 1;
    SmallestInfiniteSet() {
        smallest = 1;
    }

    int popSmallest() {
        if (mQueue.empty())
        {
            smallest++;
            return smallest - 1;
        }
        int result = mQueue.top();
        if (smallest < result)
        {
            smallest++;
            return smallest - 1;
        }
        while (!mQueue.empty() && result == mQueue.top())
        {
            mQueue.pop();
        }
        return result;
    }

    void addBack(int num) {
        if (num < smallest)
        {
            mQueue.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
