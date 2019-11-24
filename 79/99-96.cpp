class Solution
{
public:
	bool dfs(vector<vector<char>>& board, bool **sts, string &word, int row, int col, int depth)
	{
		if (row < 0 || row >= board.size() ||
			col < 0 || col >= board[0].size() ||
			sts[col][row]) return false;
		if (word[word.size() - depth] == board[row][col])
		{
			if (depth == 1) return true;
			else
			{
				sts[col][row] = true;
				if (dfs(board, sts, word, row - 1, col, depth - 1)) return true;
				if (dfs(board, sts, word, row + 1, col, depth - 1)) return true;
				if (dfs(board, sts, word, row, col - 1, depth - 1)) return true;
				if (dfs(board, sts, word, row, col + 1, depth - 1)) return true;
				sts[col][row] = false;
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string &word)
	{

		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		bool **sts = new bool*[n];
		for (int i = 0; i < n; ++i)
		{
			sts[i] = new bool[m];
			for (int j = 0; j < m; ++j) sts[i][j] = false;
		}
		int depth = word.size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == word[0])
				{
					if (depth == 1) return true;
					sts[j][i] = true;
					if (dfs(board, sts, word, i - 1, j, depth - 1)) return true;
					if (dfs(board, sts, word, i + 1, j, depth - 1)) return true;
					if (dfs(board, sts, word, i, j - 1, depth - 1)) return true;
					if (dfs(board, sts, word, i, j + 1, depth - 1)) return true;
					sts[j][i] = false;
				}
			}
		}
		return false;
	}
};