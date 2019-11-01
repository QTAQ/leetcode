#include<iostream>
#include<vector>

using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (s.size() <= numRows || numRows == 1)
		{
			return s;
		}
		int n = (2 * numRows - 2);
		string result;
		bool dir = true;
		for (int i = 0; i < numRows; i++)
		{
			dir = true;
			for (int j = i; j < s.size();)
			{
				result.append(1, s[j]);
				if (i == 0 || i == numRows - 1)
				{
					j += n;
				}
				else
				{
					if (dir)
					{
						j += (2 * (numRows - i - 1));
						dir = false;
					}
					else
					{
						j += (2 * (i - 1) + 2);
						dir = true;
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	string a = s.convert();
	return 0;
}