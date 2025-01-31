class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end(), greater<int>());
        int n = potions.size();
        for (int i = 0; i < spells.size(); i++)
        {
            if ((long long)potions.at(0) * (long long)spells.at(i) < success)
            {
                result.push_back(0);
                continue;
            }
            if ((long long)potions.at(n - 1) * (long long)spells.at(i) >= success)
            {
                result.push_back(n);
                continue;
            }
            if ((long long)potions.at(1) * (long long)spells.at(i) < success)
            {
                result.push_back(1);
                continue;
            }
            if ((long long)potions.at(n - 2) * (long long)spells.at(i) >= success)
            {
                result.push_back(n - 1);
                continue;
            }
            if (n < 4)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((long long)potions.at(j) * (long long)spells.at(i) < success)
                    {
                        result.push_back(j);
                        break;
                    }
                }
                continue;
            }
            int left = 0;
            int right = n - 1;
            int mid = (right + left) / 2;
            while (left < right && mid > 0 && mid < n - 1)
            {
                if ((long long)potions.at(mid) * (long long)spells.at(i) >= success && (long long)potions.at(mid + 1) * (long long)spells.at(i) < success)
                {
                    result.push_back(mid + 1);
                    break;
                }
                else if ((long long)potions.at(mid - 1) * (long long)spells.at(i) >= success && (long long)potions.at(mid) * (long long)spells.at(i) < success)
                {
                    result.push_back(mid);
                    break;
                }
                else if ((long long)potions.at(mid) * (long long)spells.at(i) < success)
                {
                    right = mid - 1;
                    mid = (right + left) / 2;
                }
                else
                {
                    left = mid + 1;
                    mid = (right + left) / 2;
                }
            }
        }
        return result;
    }
};
