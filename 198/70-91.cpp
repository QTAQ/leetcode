#include<vector>
using namespace std;
class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int n = nums.size();
		if (n < 2) return (n == 0) ? 0 : nums[0];
		int *dp = new int[n];
		dp[0] = nums[0];
		dp[1] = (nums[0] < nums[1]) ? nums[1] : nums[0];
		for (int i = 2; i < n; ++i)
		{
			dp[i] = (nums[i] + dp[i - 2] > dp[i - 1]) ? nums[i] + dp[i - 2] : dp[i - 1];
		}
		return dp[n - 1];
	}
};
int main()
{
	Solution s;
	vector<int> a = { 3,2,3,4 };
	s.rob(a);
	return 0;
}