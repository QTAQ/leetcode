class Solution
{
public:
	int vfind(vector<vector<int>>& matrix, int &target, int x, int y0, int y1)
	{
		int m = (y0 + y1) >> 1;
		while (y1-y0>1)
		{
			if (matrix[m][x] <= target) y0 = m;
			else y1 = m;
			m = (y0 + y1) >> 1;
		}
		return y0;
	}
	int hfind(vector<vector<int>>& matrix, int &target, int y, int x0, int x1)
	{
		int m = (x0 + x1) >> 1;
		while (x1 - x0 > 1)
		{
			if (matrix[y][m] <= target) x0 = m;
			else x1 = m;
			m = (x0 + x1) >> 1;
		}
		return x0;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int x0 = 0; int y0 = 0;
        int y1 = matrix.size();
        if(y1==0) return false;
		int x1 = matrix[0].size(); 
        if(x1==0) return false;
		if (matrix[0][0] > target || matrix[y1 - 1][x1 - 1] < target) return false;
        if (y1 == 1) return matrix[0][hfind(matrix, target, 0, x0, x1)] == target;
		if (x1 == 1) return matrix[vfind(matrix, target, 0, y0, y1)][0] == target;
		while (x1-x0>1 && y1-y0>1)
		{
			y1 = vfind(matrix, target, x0, y0, y1) + 1;
			if (y1 - y0 == 1) return matrix[y0][hfind(matrix, target, y0, x0, x1)] == target;
			x1 = hfind(matrix, target, y0, x0, x1) + 1;
			if (x1 - x0 == 1) return matrix[vfind(matrix, target, x0, y0, y1)][x0] == target;
			x0 = hfind(matrix, target, y1 - 1, x0, x1);
			if (matrix[y1 - 1][x0] != target) ++x0;
			else return true;
			y0 = vfind(matrix, target, x1 - 1, y0, y1);
			if (matrix[y0][x1 - 1] != target) ++y0;
			else return true;
		}
        if (y0 >= matrix.size() || x0 >= matrix[0].size()) return false;
		return (matrix[y0][x0] == target);
	}
};