class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairVec;
        for (int i = 0; i < n; i++)
        {
            pairVec.push_back({ nums2.at(i), nums1.at(i) });
        }
        sort(rbegin(pairVec), rend(pairVec));
        priority_queue<int, vector<int>, greater<int>> resultQueue;
        long long sum1 = 0;
        long long min2 = LLONG_MIN;
        long long result = LLONG_MIN;
        for (auto p: pairVec)
        {
            resultQueue.emplace(p.second);
            sum1 += p.second;
            min2 = p.first;
            if (resultQueue.size() > k)
            {
                sum1 -= resultQueue.top();
                resultQueue.pop();
            }
            if (resultQueue.size() == k)
            {
                result = max(result, sum1 * min2);
            }
        }
        return result;
    }
};
