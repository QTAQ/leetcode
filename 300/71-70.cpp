#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int res = 1;
		int *dp = new int[nums.size()];
		dp[nums.size() - 1] = 1;
		for (int i = nums.size()-2; i >=0; --i)
		{
			dp[i] = 1;
			for (int j = i+1; j < nums.size() ; ++j)
			{
				if (nums[j] > nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
			}
			if (dp[i] > res) res = dp[i];
		}
		
		return res;
	}
};
int main()
{
	Solution s;

	return 0;
}