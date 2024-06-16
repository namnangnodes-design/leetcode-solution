class Solution {
public:
    vector<int> countBits(int n) {
        	vector<int> result;
	for (int i = 0; i <= n; i++)
	{
		int temp = i;
		int sum = 0;
		while (temp > 0)
		{
			sum += temp & 1;
			temp /= 2;
		}
		result.push_back(sum);
	}
	return result;
    }
};
