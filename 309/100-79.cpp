#include<vector>
using namespace std;
#define max(a,b) (((a)<(b))?(b):(a))
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int i0 = 0;
		int i1 = INT32_MIN;
		int pre_i0 = 0;
		for (int i = 0; i < prices.size(); ++i)
		{
			int t = i0;
			i0 = max(i0, i1 + prices[i]);
			i1 = max(i1, pre_i0 - prices[i]);
			pre_i0 = t;
		}
		return i0;
	}
};
int main()
{
	vector<int> a = { 1, 2, 3, 0, 0, 2 };
	Solution s;
	s.maxProfit(a);

	return 0;
}