#include<vector>
#include<deque>
using namespace std;
class Solution
{
public:
	void quepush(deque<int> &q, int &n)
	{
		if (n <= q.back()) q.push_back(n);
		else
		{
			while (!q.empty() && n > q.back())
			{
				q.pop_back();
			}
			q.push_back(n);
		}
		return;
	}
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		int l = 0; int r = k - 1;
		deque<int> q;
		vector<int> res;
		q.push_back(nums[0]);
		for (int i = 1; i < k; ++i)
		{
			quepush(q, nums[i]);
		}
		res.push_back(q.front());
		while (r<nums.size()-1)
		{
			if (nums[l] == q.front()) q.pop_front();
			++l; ++r;
			quepush(q, nums[r]);
			res.push_back(q.front());
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> a = { 1,2,6,5,4,8,6,0,1,5,4 };
	int k = 3;
	vector<int> r = s.maxSlidingWindow(a, k);
	return 0;
}