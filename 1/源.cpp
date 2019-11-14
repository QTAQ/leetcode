#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int size = nums.size();
		vector<int> hash;
	}
};

int main()
{
	vector<int> nums;
	int target,n,t;
	vector<int> r;
	cin >> n;
	cout << "aaaa" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> t;
		nums.push_back(t);
	}
	cout << "aaaa" << endl;
	cin >> target;
	cout << "aaaa" << endl;
	Solution s;
	vector<int> a = s.twoSum(nums, target);
	return 0;
}