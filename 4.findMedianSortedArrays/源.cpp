#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int mid = (nums1.size() + nums2.size()) / 2.0f + 0.5f;
		vector<int>::iterator n1 = nums1.begin();
		vector<int>::iterator n2 = nums2.begin();
		bool a = true;
		int result[2] = { 0 };
		for (int i =0; i <= mid; i++)
		{
			if (n1 != nums1.end() && n2 != nums2.end())
			{
				if (*n1 < *n2)
				{
					n1++;
					a = true;
				}
				else
				{
					n2++;
					a = false;
				}
			}
			else if (n1 != nums1.end())
			{
				n1++;
				a = true;
			}
			else if (n1 != nums1.end())
			{
				n2++;
				a = false;
			}
			if (i == mid - 1)
			{
				result[0] = a ? (*(n1 - 1)) : (*(n2 - 1)); continue;
			}
			if (i == mid)
			{
				result[1] = a ? (*(n1 - 1)) : (*(n2 - 1)); continue;
			}
		}
		if ((nums1.size() + nums2.size()) % 2 == 0) return (result[0] + result[1]) / 2.0f;
		else return result[0];
	}
};





int main()
{
	vector<int> a;
	vector<int> b = {1 };
	Solution s;
	double i = s.findMedianSortedArrays(a, b);
	return 0;
}