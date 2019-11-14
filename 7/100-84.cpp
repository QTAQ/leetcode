#include<iostream>
#include<vector>

using namespace std;
class Solution
{
public:
	int reverse(int x)
	{
		if (x == INT32_MAX || x == INT32_MIN) return 0;
		long absx = (x < (int)0) ? -x : x;
		long a;
		long i = 10;
		long result = 0;
		while (true)
		{
			if (absx / i != 0)
			{
				i *= 10;
				continue;
			}
			else
			{
				i /= 10;
				a = absx / i;
				break;
			}
		}
		for (int j = 1;; j *= 10)
		{
			result += j * a;
			absx = absx - a * i;
			i /= 10;
			if (i == 0) break;
			a = absx / i;
		}
		result = (x < 0) ? -result : result;
		if (result <= INT32_MAX && result >= INT32_MIN) return result;
		else return 0;
	}
};

int main()
{
	Solution s;
	int a = INT32_MIN;
	a = s.reverse(a);
	return 0;
}