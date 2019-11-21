class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int size = nums.size();
		int *sum = new int[size];
		sum[0] = nums[0];
		int min = 0;
		int res = nums[0];
		for (int i = 1; i < size; ++i)
		{
			sum[i] = sum[i - 1] + nums[i];
			if (sum[min]<0 && sum[i] - sum[min]>res) res = sum[i] - sum[min];
			else if (sum[i] > res)
			{
				res = sum[i];
			}
			if (sum[i] < sum[min]) min = i;
		}
		return res;
	}
};