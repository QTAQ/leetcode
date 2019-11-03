#include<iostream>
#include<vector>

using namespace std;
class Solution
{
public:
	int minimumSwap( )
	{
		string s1 = "xxyyxyxyxx";
		string s2 = "xyyxyxxxyx";
		if (s1.size() != s2.size()) return -1;
		int result = 0;
		int x = 0;
		int y = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == s2[i])
			{
				continue;
			}
			else
			{
				((s1[i] == 'x') ? x : y) += 1;
			}
		}
		result += x / 2 + y / 2;
		x = x % 2;
		y = y % 2;
		if (x != y) return -1;
		result += (x == 1) ? 2 : 0;
		return result;
	}
	int numberOfSubarrays()
	{
		vector<int> nums = { 1,1,2,1,1 };
		int k = 3;
		vector<int> index;
		
		int l = 0;
		int r = 0;
		int lb = 0;
		int rb = 0;
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 != 0) index.push_back(i);
		}
		if (index.size() == 0) return 0;
		for (int i = 0; i < index.size(); i++)
		{
			lb = index[i]; 
			if (i + k - 1 < index.size())
			{
				rb = index[i + k - 1];
				if (i - 1 >= 0) l = index[i - 1]+1;
				else l = 0;
				if (i + k <= index.size()-1) r = index[i + k]-1;
				else r = nums.size() - 1;
				result += (lb - l + 1) * (r - rb + 1);
			}
			else break;
		}
		return result;
	}
	string minRemoveToMakeValid()
	{
		string s = "))((";
		vector<char> b;
		vector<int> idx;
		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '(':b.push_back(s[i]);
				idx.push_back(i);
				break;
			case ')':if (!b.empty() &&  b[b.size() - 1] == '(')
			{
				b.erase(b.end() - 1);
				idx.erase(idx.end() - 1);
			}
					 else
			{
				b.push_back(s[i]);
				idx.push_back(i);
			}
					 break;
			default: break;
			}
		}
		for (int i = idx.size()-1; i >= 0; i--)
		{
			s.erase(s.begin() + idx[i]);
		}
		return s;
	}
};

int main()
{
	Solution s;
	string a = s.minRemoveToMakeValid();
	return 0;
}