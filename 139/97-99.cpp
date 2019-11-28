#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
	bool wordBreak(string &s, vector<string>& wordDict)
	{
		int n = s.size();
		bool *dp = new bool[n];
		for (int i = 0; i < n; ++i)
		{
			dp[i] = false;
			for (int j = 0; j < wordDict.size(); ++j)
			{
				int t = i - wordDict[j].size();
				if (((t >= 0 && dp[t]) || t==-1) && s.compare(t+1, wordDict[j].size(),wordDict[j])==0) 
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n - 1];
	}
};
int main()
{
	Solution s;
	string a = "catsandog";
	vector<string>  wordDict = { "cats","sand","dog","and","cat" };
	s.wordBreak(a, wordDict);
	return 0;
}