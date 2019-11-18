class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s.size() == 0)
		{
			return 0;
		}
		int discover[256] = { -1 };
		int result = 0;
		int left = 0;
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			if (discover[s[i]] == -1)
			{
				discover[s[i]] = i + 1;
			}
			else
			{
				if (discover[s[i]] < left)
				{
					discover[s[i]] = i + 1;
				}
				else
				{
					result = ((i - left) > result) ? (i - left) : result;
					left = discover[s[i]];
					discover[s[i]] = i + 1;
				}
			}
		}
		result = ((size - left) > result) ? (size - left) : result;
		return result;
	}
};