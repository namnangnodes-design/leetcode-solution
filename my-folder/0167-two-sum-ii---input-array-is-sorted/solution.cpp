class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0;
        int b = numbers.size() - 1;
        int sum; 
        while (a < b)
        {
            sum = numbers[a] + numbers[b];
            if (sum == target)
            {
                return {a + 1, b + 1};
            }
            if (sum < target)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        return {};
    }
};
