class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxV = 0;
        vector<int> countV(1501, 0);
        vector<int> comV;
        for (int i = 0; i < nums.size(); i++)
        {
            maxV = max(maxV, nums[i]);
            if (countV[nums[i]] < 3) comV.push_back(nums[i]);
            countV[nums[i]]++; 
        }
        int countR = 0;
        while (maxV > 0)
        {
            maxV /= 2;
            countR++;
        }
        countR = pow(2, countR);
        unordered_set<int> res2;
        vector<bool> res3(countR + 1, false);
        int n = comV.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++)
            {
                res2.insert(comV[i] ^ comV[j]);
            }
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j: res2)
            {
                res3[comV[i] ^ j] = true;
            }
        }
        int result = 0;
        for (int i = 0; i < res3.size(); i++)
        {
            result += res3[i];
        }
        return result;
    }
};
