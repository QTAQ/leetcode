#include<vector>
using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int c = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (count == 0)
			{
				c = nums[i];
				count = 1;
				continue;
			}
			if (nums[i] == c) ++count;
			else --count;
		}
		return c;
	}
};

int main()
{
	Solution s;
	vector<int> a = { 2,2,1,1,1,2,2 };
	s.majorityElement(a);
	return 0;
}