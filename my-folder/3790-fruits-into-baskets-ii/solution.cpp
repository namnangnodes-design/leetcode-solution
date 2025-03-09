class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> placed;
        for (int i = 0; i < baskets.size(); i++)
        {
            placed.push_back(false);
        }
        int result = fruits.size();
        for (int i = 0; i < fruits.size(); i++)
        {
            for (int j = 0; j < baskets.size(); j++)
            {
                if (!placed[j] && baskets[j] >= fruits[i])
                {
                    placed[j] = true;
                    result--;
                    break;
                }
            }
        }
        return result;
    }
}; 

