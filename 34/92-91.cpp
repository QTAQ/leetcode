class Solution
{
public:
	int search(vector<int>& nums, int &target, int lo, int hi)
	{
		int m = (lo + hi) >> 1;
		while (hi - lo > 1)
		{
			if (nums[m] <= target) lo = m;
			else hi = m;
			m = (lo + hi) >> 1;
		}
		return (nums[lo] == target) ? lo : -1;
	}
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int hi = nums.size();
		if (hi == 0) return { -1,-1 };
		int lo = 0;
		int m = (lo + hi) >> 1;
		int a = search(nums, target, lo, hi);
		if (a == -1) return { -1,-1 };
		else
		{
			int l = a;
			int r = a;
			while (l > 0)
			{
				int t = search(nums, target, 0, l);
				if (t != -1) l = t;
				else break;
			}
			while (r < hi - 1)
			{
				int t = search(nums, target, r + 1, hi);
				if (t != -1) r = t;
				else break;
			}
			return { l,r };
		}

	}
};