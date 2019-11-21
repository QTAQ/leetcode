#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		vector<vector<int>> c = matrix;
		for (int i = n-1; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				matrix[j][i] = c[n-i-1][j];
			}
		}
		return;
	}
};
int main()
{
	vector<vector<int>> matrix =
	{
		{5, 1, 9, 11},
			{2, 4, 8, 10},
			{13, 3, 6, 7},
			{15, 14, 12, 16}
	};
	Solution s;
	s.rotate(matrix);
	
	return 0;
}