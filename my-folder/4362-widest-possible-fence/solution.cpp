class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        unordered_map<int, int> pMap;
        vector<int> key;
        unordered_map<int, int> sMap;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (pMap[planks[i]] == 0)
            {
                key.push_back(planks[i]);
            }
            pMap[planks[i]]++;
        }
        // for (auto &s: pMap)
        // {
        //     printf("plank %d have %d \n", s.first, s.second);
        // }
        // for (int i = 0; i < key.size(); i++)
        // {
        //     printf("key %d is %d \n", i, key[i]);
        // }
        for (int i = 0; i < key.size(); i++)
        {
            if (pMap[key[i]] >= 2)
            {
                sMap[key[i] * 2] += pMap[key[i]] / 2; 
            }
            for (int j = i + 1; j < key.size(); j++)
            {
                sMap[key[i] + key[j]] += min(pMap[key[i]], pMap[key[j]]);
            }
        }
        // for (auto &s: sMap)
        // {
        //     printf("sum %d have %d \n", s.first, s.second);
        // }
        for (int i = 0; i < key.size(); i++)
        {
            int temp = pMap[key[i]] + sMap[key[i]];
            res = max(temp, res);
            //printf("key %d p %d s %d \n", key[i], pMap[key[i]], sMap[key[i]]);
        }
        for (auto &s: sMap)
        {
            int temp = pMap[s.first] + s.second;
            //printf("sum %d p %d s %d \n", s.first, pMap[s.first], s.second);
            res = max(temp, res);
        }
        return res;
    }
};
