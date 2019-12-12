class Solution
{
public:
	vector<int> findAnagrams(string &s, string &p)
	{
		vector<int> res;
		unordered_map<char, int> m;
		unordered_map<char, int> t;
		for (int i = 0; i < p.size(); ++i) ++m[p[i]];
		int lo = 0; int hi = p.size() - 1;
		int b = -1;
		while (hi < s.size())
		{
			int beg = (b == -1) ? lo : b;
			while (lo <= hi)
			{
				if (m.find(s[lo]) == m.end())
				{
					b = -1;
					hi += lo - beg + 1;
					++lo;
					t.clear();
					break;
				}
				++t[s[lo]];
				if (t[s[lo]] > m[s[lo]])
				{
					int i = beg;
					while (t[s[lo]] > m[s[lo]]) --t[s[i++]];
					b = i;
					hi = b + p.size() - 1;
					++lo; break;
				}
				++lo;
			}
			if (lo > hi)
			{
				res.push_back(beg);
				--t[s[beg]];
				b = beg + 1;
				++hi;
			}
		}
		return res;
	}
};