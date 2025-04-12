class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2)
        {
            return n;
        }
        else
        {
            int count = 0;
            while (n != 0 && n != 1)
            {
                n = n >> 1;
                count++;
            }
            return pow(2, (count + 1));
        }
        return 0;
    }
};
