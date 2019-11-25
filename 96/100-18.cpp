class Solution
{
public:
	int numTrees(int n)
	{
		int *dp = new int[n + 1];
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < n + 1; ++i)
		{
			dp[i] = dp[i - 1] * 2;
			int l = 1; int r = i - 2;
			while (l < r)
			{
				dp[i] += dp[l] * dp[r] * 2;
				++l; --r;
			}
			if (l == r)
			{
				dp[i] += dp[l] * dp[r];
			}
		}
		return dp[n];
	}
};