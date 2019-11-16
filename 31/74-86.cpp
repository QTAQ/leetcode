#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution //74-86
{
public:
	inline void myswap(int &a, int &b)
	{
		int t = a;
		a = b;
		b = t;
	}
	void reverse(vector<int>& nums, int l, int r)
	{
		if (l != -1)
		{
			int a = nums[l];
			for (int i = r; i >= l; --i)
			{
				if (nums[i] > a)
				{
					myswap(nums[i], nums[l]);
					break;
				}
			}
		}
		++l;
		while (l < r) { myswap(nums[l], nums[r]); ++l; --r; }
	}
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		if (size < 2) return;
		int r = size - 1;
		int l = -1;
		for (int i = r - 1; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				l = i;
				break;
			}
		}
		reverse(nums, l, r);
		return;
	}
};
class Solution1 //74-86
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		if (size < 2) return;
		int l;
		for (l = size - 2; l >= 0; --l)
		{
			if (nums[l] < nums[l + 1])
			{
				break;
			}
		}
		if (l == -1)
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			int i;
			for (i = size-1; i >= 0; --i)
			{
				if (nums[i] > nums[l])
				{
					break;
				}
			}
			swap(nums[l], nums[i]);
			reverse(nums.begin() + l + 1, nums.end());
		}
		return;
	}
};
int main()
{
	vector<int> nums = { 1,2,3 };
	Solution s;
	s.nextPermutation(nums);
	return 0;
}