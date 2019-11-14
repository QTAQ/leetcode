#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
	vector<string> res;
	void search(int l, int r, int &stk, string &t)
	{
		if (l == 0 && r == 0)
		{
			res.push_back(t); return;
		}
		if (stk != 0)
		{
			int temp = stk;
			string t_copy = t;
			if (l != 0)
			{
				++stk; t += '(';
				search(l - 1, r, stk, t);
			}
			--temp; t_copy += ')';
			search(l, r - 1, temp, t_copy);
		}
		else
		{
			++stk; t += '(';
			search(--l, r, stk, t);
		}
		return;
	}
	vector<string> generateParenthesis(int n)
	{
		if (n == 0) return res;
		int stk = 0;
		string t;
		search(n, n, stk, t);
		return res;
	}
};
int main()
{
	Solution s;
	s.generateParenthesis(4);
	return 0;
}