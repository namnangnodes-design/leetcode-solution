class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> numSet;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            for (int j = n - 1, k = 0; j > -1; j--, k++)
            {
                num += (nums[i][j] - 48) * (int)pow(2, k);
            }
            numSet.insert(num);
        }
        for (int i = 0; i <= pow(2, n); i++)
        {
            if (numSet.find(i) == numSet.end())
            {
                string binary = "";
                if (i == 0) binary = "0"; 
                while (i > 0) {
                    binary = (i % 2 == 0 ? "0" : "1") + binary;
                    i /= 2;
                }
                string res = "";
                for (int j = 0; j < n - binary.size(); j++)
                {
                    res.push_back('0');
                }
                res.append(binary);
                return res;
            }
        }
        return "";
    }
};
