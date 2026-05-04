class MyQueue {
public:
    stack<int> s0;
    stack<int> s1;
    MyQueue() {
    }
    
    void push(int x) {
        s0.push(x);
    }
    
    int pop() {
        if (empty())
        {
            return -1;
        }
        int res;
        while (!s0.empty())
        {
            s1.push(s0.top());
            s0.pop();
        }
        res = s1.top();
        s1.pop();
        while (!s1.empty())
        {
            s0.push(s1.top());
            s1.pop();
        }
        return res;
    }
    
    int peek() {
        if (empty())
        {
            return -1;
        }
        int res;
        while (!s0.empty())
        {
            s1.push(s0.top());
            s0.pop();
        }
        res = s1.top();
        while (!s1.empty())
        {
            s0.push(s1.top());
            s1.pop();
        }
        return res;
    }
    
    bool empty() {
        return s0.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
