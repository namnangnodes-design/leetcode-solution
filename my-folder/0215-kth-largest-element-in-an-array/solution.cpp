class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        	priority_queue<int> mQueue;
	for (int i = 0; i < nums.size(); i++)
	{
		mQueue.push(nums[i]);
	}
	for (int i = 1; i < k; i++)
	{
		mQueue.pop();
	}
	return mQueue.top();
    }
};
