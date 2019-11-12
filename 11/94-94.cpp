#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int result = 0;
		for (int i = 0, j = height.size() - 1; i != j;)
		{
			if (height[i] < height[j])
			{
				result = (result < (j - i)*height[i]) ? (j - i)*height[i] : result;
				i++;
			}
			else
			{
				result = (result < (j - i)*height[j]) ? (j - i)*height[j] : result;
				j--;
			}
		}
		return result;
	}
};

int main()
{
	
	return 0;
}