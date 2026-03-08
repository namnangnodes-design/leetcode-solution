class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a = 0;
        long long int b = sqrt(c) + 1;
        long long int sum;
        while (a <= b)
        {
            sum = a * a + b * b;
            if (sum == c)
            {
                return true;
            }
            else if (sum < c)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        return false;
    }
};
