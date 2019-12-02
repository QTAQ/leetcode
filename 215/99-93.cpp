#include<vector>
using namespace std;

class Solution
{
public:
	int partition(vector<int>& nums, int lo, int hi)
	{
		int r = rand() % (hi - lo);
		swap(nums[lo], nums[lo + r]);
		r = nums[lo];
		while (lo<hi)
		{
			while (lo < hi && nums[hi] >= r) --hi;
			nums[lo] = nums[hi];
			while (lo < hi && nums[lo] <= r) ++lo;
			nums[hi] = nums[lo];
		}
		nums[lo] = r;
		return lo;
	}
	int findKthLargest(vector<int>& nums, int k)
	{
		int t = nums.size() - k;
		int a = partition(nums, 0, nums.size()-1);
		int l = 0;
		int r = nums.size() - 1;
		while (a!=t)
		{
			if (a < t)
			{
				l = a;
				a = partition(nums, a + 1, r);
			}
			else
			{
				r = a;
				a = partition(nums, l, a - 1);
			}
		}
		return nums[t];
	}
};

int main()
{
	Solution s;
	vector<int> a = { 3,2,1,5,6,4
	};
	s.findKthLargest(a,2);
	return 0;
}