class Solution {
    public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int i: nums )
        {
            if ((i <= 100 && i >= 10) || (i <= 9999 && i >= 1000) || i == 100000) result++;
        }
        return result;
    }
};
