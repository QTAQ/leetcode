class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int size = s.size();
		if (size < 2) return 0;
		int r = 0;
		int *dp = new int[size];
		for (int i = 0; i < size; i++)
		{
			dp[i] = 0;
		}
		if (s[0] == '('&&s[1] == ')')
		{
			dp[0] = 0; dp[1] = 2;
			r = 2;
		}
		for (int i = 2; i < size; ++i)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = dp[i - 2] + 2;
				}
				else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
				{
					if (i - 2 - dp[i - 1] >= 0)
					{
						dp[i] = dp[i - 2 - dp[i - 1]] + dp[i - 1] + 2;
					}
					else
					{
						dp[i] = dp[i - 1] + 2;
					}
				}
				r = (dp[i] > r) ? dp[i] : r;
			}
		}
		return r;
	}
};