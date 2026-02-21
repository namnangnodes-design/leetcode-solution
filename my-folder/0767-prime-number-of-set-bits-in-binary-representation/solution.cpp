class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++)
        {
            int setBit = __builtin_popcount(i);
            bool isPrime = true;
            for (int j = 2; j <= sqrt(setBit); j++)
            {
                if (setBit % j == 0)
                {
                    isPrime = false;
                    break;
                } 
            }
            if (setBit == 2 || setBit == 3) isPrime = true;
            if (setBit == 0 || setBit == 1) isPrime = false;
            if (isPrime) res++;
        }
        return res;
    }

};
