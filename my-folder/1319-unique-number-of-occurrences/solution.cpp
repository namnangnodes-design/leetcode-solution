class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int countNumArr[2001];
        int countCountArr[1001];
        for (int i = 0; i < 1001; i++)
        {
            countCountArr[i] = 0;
        }
        for (int i = 0; i < 2001; i++)
        {
            countNumArr[i] = 3000;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (countNumArr[arr.at(i) + 1000] == 3000)
            {
                countNumArr[arr.at(i) + 1000] = 1;
            }
            else
            {
                countNumArr[arr.at(i) + 1000]++;
            }
        }
        for (int i = 1; i < 2001; i++)
        {
            if (countNumArr[i] == 3000)
            {
                continue;
            }
            else if (countCountArr[countNumArr[i]] == 0)
            {
                countCountArr[countNumArr[i]] = 1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
