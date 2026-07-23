class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return n;
        }
        else
        {
            int bits = 0;
            while (n != 0)
            {
                n /= 2;
                bits++;
            }
            return pow(2, bits);
        }
    }
};
