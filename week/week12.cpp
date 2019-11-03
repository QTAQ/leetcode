#include<iostream>
#include<vector>

using namespace std;
class Solution
{
public:
	vector<int> transformArray( )
	{
		vector<int> arr = { 6,2,3,4 };
		vector<int> c(arr.size());
		bool f = false;
		c[0] = arr[0]; c[c.size() - 1] = arr[c.size() - 1];
		do
		{

			for (int i = 1; i < c.size() - 1; i++)
			{
				if (arr[i - 1]<arr[i] && arr[i]>arr[i + 1])
				{
					c[i] = -1;
					continue;
				}
				if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
				{
					c[i] = 1;
					continue;
				}
				else c[i] = 0;
			}
			f = false;
			for (int i = 1; i < c.size()-1; i++)
			{
				if (c[i] != 0) f = true;
				arr[i] += c[i];
			}
		} while (f);
		return c;
	}
	int treeDiameter(vector<vector<int>>& edges)
	{

	}
};

int main()
{
	Solution s;
	s.transformArray();
	return 0;
}