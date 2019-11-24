class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int r = 0; int w = 0; int b = 0; int size = nums.size();
		for (int i = 0; i < size; ++i)
		{
			switch (nums[i])
			{
			case 0:++r; break;
			case 1:++w; break;
			default:++b; break;
			}
		}
		int i = 0;
		for (size = r; i < size; ++i)
		{
			nums[i] = 0;
		}
		for (size = r + w; i < size; ++i)
		{
			nums[i] = 1;
		}
		for (size = r + w + b; i < size; ++i)
		{
			nums[i] = 2;
		}
	}
};