class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> sQ;
        for (int i = 0; i < n; i++)
        {
            sQ.push(stones[i]);
        }
        while (sQ.size() > 1)
        {
            int a = sQ.top();
            sQ.pop();
            int b = sQ.top();
            sQ.pop();
            if (a != b)
            {
                sQ.push(abs(a - b));
            }
        }
        return sQ.empty() ? 0 : sQ.top();
    }
};
