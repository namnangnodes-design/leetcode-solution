class HitCounter {
public:
    queue<int> hitQueue;

    HitCounter() {
    }
    
    void hit(int timestamp) {
        hitQueue.push(timestamp);
    }
    
    int getHits(int timestamp) {
        int cur = hitQueue.front();
        while (!hitQueue.empty() && cur <= timestamp - 300)
        {
            hitQueue.pop();
            cur = hitQueue.front();
        }
        return hitQueue.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
