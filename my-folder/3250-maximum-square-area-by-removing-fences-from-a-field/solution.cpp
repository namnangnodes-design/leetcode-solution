class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        unordered_set<int> hDiff;
        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = 0; j < hFences.size(); j++)
            {
                if (hFences[i] - hFences[j] > 0) hDiff.insert(hFences[i] - hFences[j]);
            }
        }
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> vDiff;
        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = 0; j < vFences.size(); j++)
            {
                if (vFences[i] - vFences[j] > 0) vDiff.insert(vFences[i] - vFences[j]);
            }
        }
        long long int res = -1;
        for (int i: hDiff)
        {
            if (vDiff.find(i) != vDiff.end())
            {
                if (i > res) res = i;
            }
        }
        if (res == -1) return -1;
        long long int bigRes = res % 1000000007 * res;
        return res  % 1000000007 * res % 1000000007;
    }
};
