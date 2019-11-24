#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int max = 0;
		heights.push_back(-1);
		vector<int> stk;
		stk.push_back(-1);
		for (int i = 0; i < heights.size(); ++i)
		{
			if (stk.back() == -1 || heights[i] >= heights[stk.back()]) stk.push_back(i);
			else
			{
				int top = stk.back();
				while (top != -1 && heights[top] > heights[i])
				{
					stk.pop_back();
					int t = (i - stk.back() - 1)*heights[top];
					if (t > max) max = t;
					top = stk.back();
				}
				stk.push_back(i);
			}
		}
		return max;
	}
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		int res = 0;
		int m = matrix.size(); if (m == 0) return 0;
		int n = matrix[0].size();
		vector<int> heights(n, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
			}
			int max = largestRectangleArea(heights);
			if (max > res) res = max;
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<char>> a = {
		{'1', '0', '1', '0', '0'},
			{'1', '0', '1', '1', '1'},
			{'1', '1', '1', '1', '1'},
	{'1', '0', '0', '1', '0'}};
	int q = s.maximalRectangle(a);
	return 0;
}