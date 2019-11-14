#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		vector<int> resultA;
		long result = 0;
		bool sign = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (resultA.size() == 0)
			{
				switch (str[i])
				{
				case '+':if (i + 1 < str.size() && (str[i + 1] < 48 || str[i + 1]>57))
				{
					return 0;
				}
						 else break;
				case '-':if (i + 1 < str.size() && (str[i + 1] < 48 || str[i + 1]>57))
				{
					return 0;
				}
						 else
				{
					sign = false;
					break;
				}
				case ' ':break;
				default:
					if (str[i] < 48 || str[i]>57)
					{
						return 0;
					}
					else resultA.push_back(str[i] - 48);
					break;
				}
				continue;
			}
			if (str[i] < 48 || str[i]>57) break;
			else resultA.push_back(str[i] - 48);
		}
		int i = 0;
		for (; i < resultA.size(); i++)
		{
			if (resultA[i] == 0) continue;
			else break;
		}
		if (i == resultA.size()) return 0;
		if (resultA.size() - i > 10) return sign ? INT32_MAX : INT32_MIN;
		long j = 1;
		for (int k = resultA.size() - 1; k >= i; k--, j *= 10)
		{
			result += j * resultA[k];
		}
		result = sign ? result : -result;
		if (result < INT32_MIN) return INT32_MIN;
		if (result > INT32_MAX) return INT32_MAX;
		return result;
	}
};
int main()
{
	Solution s;
	int a = s.myAtoi();
	return 0;
}