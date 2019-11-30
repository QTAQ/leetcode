class Solution
{
public:
	void dfs(int i, int j, int &m, int &n, vector<vector<char>>& grid, bool **f)
	{
		if (i < 0 || i == m ||
			j < 0 || j == n ||
			grid[i][j] == '0'
			|| f[j][i]) return;
		f[j][i] = true;
		dfs(i + 1, j, m, n, grid, f);
		dfs(i, j + 1, m, n, grid, f);
		dfs(i - 1, j, m, n, grid, f);
		dfs(i, j - 1, m, n, grid, f);
	}
	int numIslands(vector<vector<char>>& grid)
	{
		int m = grid.size(); if (m == 0) return 0;
		int n = grid[0].size();
		bool **f = new bool*[n];
		/*	bool f[3][3];*/
		for (int i = 0; i < n; ++i)
		{
			f[i] = new bool[m];
			for (int j = 0; j < m; ++j)
			{
				f[i][j] = false;
			}
		}
		int res = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (f[j][i]) continue;

				if (grid[i][j] == '1')
				{
					++res;
					dfs(i, j, m, n, grid, f);
				}
			}
		}
		return res;
	}
};