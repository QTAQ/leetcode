class Solution
{
public:
	int mymin(int &a, int &b, int&c)
	{
		if (a < b) return (a < c) ? a : c;
		else return (b < c) ? b : c;
	}
	int minDistance(string word1, string word2)
	{
		int m = word1.size(); int n = word2.size();
		if (m == 0) return n;
		if (n == 0) return m;
		int **dp = new int*[n];
		dp[0] = new int[m];
		dp[0][0] = (word1[0] == word2[0]) ? 0 : 1;
		for (int i = 1; i < n; ++i)
		{
			dp[i] = new int[m];
			dp[i][0] = (word1[0] == word2[i]) ? i : dp[i - 1][0] + 1;
		}
		for (int i = 1; i < m; ++i)
		{
			dp[0][i] = (word1[i] == word2[0]) ? i : dp[0][i - 1] + 1;
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[j][i] = (word1[i] == word2[j]) ? dp[j - 1][i - 1] :
					mymin(dp[j - 1][i - 1], dp[j][i - 1], dp[j - 1][i]) + 1;
			}
		}
		return dp[n - 1][m - 1];
	}
};