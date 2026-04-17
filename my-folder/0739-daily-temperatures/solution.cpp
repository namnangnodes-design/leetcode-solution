class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty())
            {
                int l = s.top();
                if (temperatures[l] < temperatures[i])
                {
                    res[l] = i - l;
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push(i);
        }
        return res;
    }
};
