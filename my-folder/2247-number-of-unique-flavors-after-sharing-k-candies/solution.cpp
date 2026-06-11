class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int n = candies.size();
        int temp = 0;
        int res = 0;
        unordered_map<int, int> tM; 
        for (int i = k; i < n; i++)
        {
            tM[candies[i]]++;
        }
        temp = tM.size();
        if (temp > res)
        {
            res = temp;
        }
        for (int i = k; i < n; i++)
        {
            if (candies[i] == candies[i - k])
            {
                continue;
            }
            else
            {
                tM[candies[i]]--;
                if (tM[candies[i]] == 0)
                {
                    temp--;
                }
                if (tM.find(candies[i - k]) == tM.end() || tM[candies[i - k]] == 0)
                {
                    temp++;
                }
                tM[candies[i - k]]++;
                if (temp > res)
                {
                    res = temp;
                }
            }
        }
        return res;
    }
};
