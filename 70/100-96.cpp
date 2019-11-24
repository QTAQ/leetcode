class Solution
{
public:
	int climbStairs(int n)
	{
		int a = 1; int b = 1;
		int t = 0;
		for (int i = 1; i < n; ++i)
		{
			t = b;
			b += a;
			a = t;
		}
		return b;
	}
};