class Solution {
public:
    int arr[18] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};

    int minOperations(int n) {
        int res = 0;
        while (n != 0)
        {
            int i = 0;
            for (i = 0; i < 19; i++)
            {
                if (n < arr[i])
                {
                    break;
                }
            }
            if (i == 0)
            {
                return res;
            }
            if (n - arr[i - 1] <= arr[i] - n)
            {
                n -= arr[i - 1];
            }
            else
            {
                n = arr[i] - n;
            }
            res++;
        }
        return res;
    }
};
