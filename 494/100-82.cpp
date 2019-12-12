#include<vector>
using namespace std;
class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		int sum = 0;
		for (int &i : nums) sum += i;
		if (sum < S) return 0;
		sum += S;
		if ((sum & 1) == 1) return 0;
		sum >>= 1;
		vector<int> dp(sum + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = dp.size()-1; j >= 0; --j)
			{
				if(j - nums[i] >=0 ) dp[j] += dp[j - nums[i]];
			}
		}
		return dp[sum];
	}
};
int main()
{
	Solution s;
	vector<int> a = { 1,2,7,9,981 };
	int S = 1000000000;
	auto q = s.findTargetSumWays(a, S);
	return 0;
}