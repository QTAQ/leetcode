#include<vector>
#include<algorithm>
using  namespace std;
class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> dp(amount+1, -1);
		dp[0] = 0;
		sort(coins.begin(), coins.end());
		for (int i = 1; i < dp.size(); ++i)
		{
			int mi = INT32_MAX;
			for (int j = 0; j < coins.size() && coins[j]<=i; ++j)
			{
				int t = dp[i - coins[j]];
				if (t != -1 && t + 1 < mi) mi = t + 1;
			}
			if (mi != INT32_MAX) dp[i] = mi;
		}
		return dp[amount];
	}
};
int main()
{
	Solution s;
	vector<int> a = { 1,2,5 };
	int q = ;
	s.coinChange(a, q);
	return 0;
}