class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> resultList;
        int countArr[10001];
        for (int i = 0; i < 10001; i++)
        {
            countArr[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (countArr[nums.at(i)] != 0)
            {
                resultList.push_back(nums.at(i));
            }
            else
            {
                countArr[nums.at(i)]++;
            }
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if (countArr[i] == 0)
            {
                resultList.push_back(i);
            }
        }
        return resultList;
    }
};
