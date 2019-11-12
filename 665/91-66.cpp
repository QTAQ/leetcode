#include<vector>
using namespace std;

class Solution
{
public:
	bool checkPossibility(vector<int>& nums)
	{
		if (nums.size() == 1) return true;
		int a = 0;
		if (nums[0] > nums[1]) a++;
		for (int i = 2; i<nums.size(); i++)
		{
			if (nums[i - 1] > nums[i])
			{
				if (nums[i - 2] > nums[i])
				{
					nums[i] = nums[i - 1];
				}
				a++;
			}
			if (a == 2) return false;
		}
		return true;
	}
};
int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(3);
	s.checkPossibility(nums);
	return 0;
}