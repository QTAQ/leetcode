class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		int minus = 1;
		int max = nums[0];
		int res = 1;
		int m = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				res = 1; minus = 1; m = 0;
				if (nums[i] > max) max = nums[i];
				continue;
			}
			res *= nums[i];
			if (nums[i] < 0)
			{
				++m;
				if (m == 1)
				{
					minus = res;
					if (res > max) max = res;
					continue;
				}
			}
			if (m % 2 == 0)
			{
				if (res > max) max = res;
			}
			else
			{
				if (res / minus > max) max = res / minus;
			}
		}
		return max;
	}
};