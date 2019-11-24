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
};