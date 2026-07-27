class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxV, secondV, maxI, secondI;
        if (nums[0] >= nums[1])
        {
            maxV = nums[0];
            secondV = nums[1];
            maxI = 0;
            secondI = 1;
        }
        else
        {
             maxV = nums[1];
            secondV = nums[0];
            maxI = 1;
            secondI = 0;
        }
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] >= maxV)
            {
                secondV = nums[maxI];
               secondI = maxI;
                maxV = nums[i];
                maxI = i;
                
            }
            else if (nums[i] >= secondV)
            {
                secondV = nums[i];
                secondI = i;
            }
        }
        printf("%d %d", maxI, secondI);
        return (nums[maxI] - 1) * (nums[secondI] - 1);
    }
};
