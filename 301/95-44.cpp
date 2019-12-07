#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution
{
public:
	vector<string> res;
	unordered_set<string> st;
	void dfs(string &s, string &path, int stk, int i, int l, int r)
	{
		if (i >= s.size())
		{
			if (stk == 0 && st.find(path) == st.end())
			{
				res.push_back(path);
				st.insert(path);
			}
			return;
		}
		switch (s[i])
		{
		case '(':
			if (l != 0)
			{
				dfs(s, path, stk, i + 1, l -1, r);
			}
			path += s[i];
			dfs(s, path, stk+1, i + 1, l, r);
			path.pop_back();
			break;
		case ')':
			if (r != 0)
			{
				dfs(s, path, stk, i + 1, l, r - 1);
			}
			if (stk == 0) return;
			else
			{
				path += s[i];
				dfs(s, path, stk-1, i + 1, l, r);
				path.pop_back();
			}
			break;
		default:
			path += s[i];
			dfs(s, path, stk, i + 1, l, r);
			path.pop_back();
			break;
		}
	}
	vector<string> removeInvalidParentheses(string &s)
	{
		int stk = 0;
		int l = 0; int r = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			switch (s[i])
			{
			case '(':
				++stk;
				++l;
				break;
			case ')':
				if (stk != 0)
				{
					--stk;
					--l;
				}
				else ++r;
				break;
			default:
				break;
			}
		}
		string path;
		dfs(s, path, 0, 0, l, r);
		return res;
	} 
};
int main()
{
	string a = { "()())()" };
	Solution s;
	vector<string> res = s.removeInvalidParentheses(a);
	return 0;
}