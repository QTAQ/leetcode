class Solution
{
public:
	int trap(vector<int>& height)
	{
		int size = height.size();
		int l = 1;
		int r = size - 2;
		int maxl = 0;
		int maxr = 0;
		int sum = 0;
		for (int i = 1; i < size - 1; ++i)
		{
			if (height[l - 1] < height[r + 1])
			{
				maxl = (height[l - 1] > maxl) ? height[l - 1] : maxl;
				if (maxl > height[l]) sum += (maxl - height[l]);
				++l;
			}
			else
			{
				maxr = (height[r + 1] > maxr) ? height[r + 1] : maxr;
				if (maxr > height[r]) sum += (maxr - height[r]);
				--r;
			}
		}
		return sum;
	}
};