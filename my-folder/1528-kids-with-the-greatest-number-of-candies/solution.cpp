class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = candies[0];
        vector<bool> result;
        for (int i = 1; i < candies.size(); i++)
        {
            if (maxC < candies[i])
            {
                maxC = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++)
        {
            result.push_back(candies[i] + extraCandies >= maxC);
        }
        return result;
    }
};
