class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> count;
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] == 0) continue;
            for (int j = 0; j < digits.size(); j++)
            {
                if (i == j) continue;
                for (int k = 0; k < digits.size(); k++)
                {
                    if (k == i || k == j || digits[k] % 2 == 1) continue;
                    int temp = digits[i] * 100;
                    temp += digits[j] * 10;
                    temp += digits[k];
                    count.insert(temp);
                }
            }
        }
        // for (int c: count)
        // {
        //     printf("c %d \n", c);    
        // }
        return count.size();
    }
};
