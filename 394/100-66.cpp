#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution
{
public:
	unordered_set<char> st = { '1','2','3','4','5','6','7','8','9' };
	void construct(string &s, string &res, int lo, int hi)
	{
		while (lo <= hi)
		{
			if (st.find(s[lo]) == st.end())
			{
				res += s[lo];
				++lo;
			}
			else
			{
				string t;
				int k = 0;
				while (lo < hi)
				{
					if (s[lo] != '[') t += s[lo];
					else break;
					++lo;
				}
				k = atoi(t.c_str());
				string tmp;
				int beg = lo + 1;
				int end = beg;
				int stk = 1;
				while (stk != 0)
				{
					switch (s[end])
					{
					case '[':
						++stk;
						break;
					case ']':
						--stk;
						break;
					default:
						break;
					}
					++end;
				}
				construct(s, tmp, beg, end-2);
				while (k--) res += tmp;
				lo = end;
			}
		}
	}
	string decodeString(string s)
	{
		if (s.empty()) return "";
		string res;
		construct(s, res, 0, s.size() - 1);
		return res;
	}
};
int main()
{
	Solution s;
	string a = "2[abc]3[cd]ef";
	string w = "";
	w= s.decodeString(a);
	return 0;
}