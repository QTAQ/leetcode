#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int size = nums.size();
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		if (size < 3 || nums.back()<=0) return result;
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] > 0) break;
			int j = i + 1;
			int k = size - 1;
			while (j < k)
			{
				int temp = nums[i] + nums[j] + nums[k];
				if (temp == 0)
				{
					vector<int> t = { nums[i] , nums[j] , nums[k] };
					result.push_back(t);
					while (k - 1 > j && nums[k - 1] == nums[k]) --k;
					--k;
					while (j + 1 < k && nums[j + 1] == nums[j]) ++j;
					++j;
				}
				else  if (temp > 0)
				{
					while (k - 1 > j && nums[k - 1] == nums[k]) --k;
					--k;
				}
				else
				{
					while (j + 1 < k && nums[j + 1] == nums[j]) ++j;
					++j;
				}
			}
			while (i + 1 < size && nums[i + 1] == nums[i]) ++i;
		}
		return result;
	}
};
int main()
{	
	Solution s;
	vector<int> a = { -2,0,1,1,2 };
	vector<vector<int>> b = s.threeSum(a);
}