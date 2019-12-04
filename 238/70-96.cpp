#include<vector>
using namespace std;
class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int idx = -1;
		int pro = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				if (idx == -1)
				{
					idx = i;
					continue;
				}
				else
				{
					idx = -2;
					break;
				}
			}
			pro *= nums[i];
		}
		if (idx == -2) return vector<int>(nums.size(), 0);
		else if (idx == -1)
		{
			vector<int> res(nums.size());
			for (int i = 0; i < res.size(); ++i)
			{
				res[i] = pro / nums[i];
			}
			return res;
		}
		else
		{
			vector<int> res(nums.size(),0);
			res[idx] = pro;
			return res;
		}
	}
};