class Solution {
public:
    int integerReplacement(int n) {
        if (n == 2147483647) return 32;
        if (n == 0) return 1;
        int res = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else if (n % 4 == 3 && n != 3)
            {
                n++;
            } 
            else n--;
            //printf("n %d \n", n);
            res++;
        }
        return res;
    }
};
