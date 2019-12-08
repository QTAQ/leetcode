#include<vector>
using namespace std;
#define max(a,b) (((a)<(b))?(b):(a))
class Solution
{
public:
	int maxCoins(vector<int>& nums)
	{
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
		for (int i = nums.size()-2; i >= 0; --i)
		{
			for (int j = i+2; j < nums.size(); ++j)
			{
				int m = 0;
				for (int k = i+1; k < j; ++k)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
					if (dp[i][j] > m) m = dp[i][j];
				}
				dp[i][j] = m;
			}
		}
		return dp[0][nums.size()-1];
	}
};
int main()
{
	vector<int> a = { 3, 1, 5, 8 };
	Solution s;
	int q = s.maxCoins(a);
	return 0;
}