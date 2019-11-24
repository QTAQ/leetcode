class Solution
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int n = grid.size(); int m = grid[0].size();
		int **dp = new int*[m];
		dp[0] = new int[n]; dp[0][0] = grid[0][0];
		for (int i = 1; i < m; ++i)
		{
			dp[i] = new int[n];
			dp[i][0] = dp[i - 1][0] + grid[0][i];
		}
		for (int i = 1; i < n; ++i)
		{
			dp[0][i] = dp[0][i - 1] + grid[i][0];
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = grid[j][i] + ((dp[i - 1][j] < dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]);
			}
		}
		return dp[m - 1][n - 1];
	}
};
