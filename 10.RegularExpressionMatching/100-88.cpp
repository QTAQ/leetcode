#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (p.size() == 0)
		{
			return (s.size() == 0) ? true : false;
		}
		bool **dp = new bool*[s.size() + 1];
		for (int i = 0; i < s.size() + 1; i++)
		{
			dp[i] = new bool[p.size() + 1];
			dp[i][0] = false;
		}
		dp[0][0] = true;
		dp[0][1] = false;
		for (int i = 2; i < p.size() + 1; i++)
		{
			dp[0][i] = (p[i - 1] == '*'&&dp[0][i - 2]) ? true : false;
		}
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < p.size(); j++)
			{
				switch (p[j])
				{
				case '.':
					dp[i + 1][j + 1] = dp[i][j];
					break;
				case '*':
					dp[i + 1][j + 1] = (p[j - 1] != s[i] && p[j - 1] != '.') ? dp[i + 1][j - 1] : (dp[i + 1][j] || dp[i + 1][j - 1] || dp[i][j + 1]);
					break;
				default:
					dp[i + 1][j + 1] = (s[i] == p[j]) ? dp[i][j] : false;
					break;
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};
int main()
{
	Solution s;
	return 0;
}