#include<vector>
using namespace std;
class Solution
{
public:
	bool canPartition(vector<int>& nums)
	{
		int sum = 0;
		for (int &i : nums) sum += i;
		if (sum & 1 == 1) return false;
		sum /= 2;
		vector<int> dp(sum + 1, false);
		dp[0] = true;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = sum; j >=0 ; --j)
			{
				if(j-nums[i]>=0) 
					dp[j] = dp[j] || dp[j - nums[i]];	
			}
			if (dp[sum]) return true;
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<int> a = { 2,2,3,4,5 };
	auto q = s.canPartition(a);
	return 0;
}