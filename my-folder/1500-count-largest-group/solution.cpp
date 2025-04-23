static int result[10001] = {0};

class Solution {
public:
    int countLargestGroup(int n) {

        if (result[n] == 0)
        {
            int maxCount = 0;
            int sumDigit[37] = {0};
            for (int i = 1; i <= n; i++)
            {
                int temp = i;
                int sum = 0;
                while (temp > 0)
                {
                    sum += temp % 10;
                    temp /= 10;
                }
                sumDigit[sum]++;
                maxCount = max(maxCount, sumDigit[sum]);
            }
            for (int i = 1; i < 37; i++)
            {
                if (sumDigit[i] == maxCount)
                {
                    result[n]++;
                }
            }
        }
        return result[n];
    }
};
