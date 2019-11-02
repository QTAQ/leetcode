#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring( )
	{
		string s = "abba";
		if (s.size() == 0)
		{
			return 0;
		}
		unordered_map<char, int> discover;
		string temp;
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '\0') break;
			if (discover.count(s[i]) == 0)
			{
				discover[s[i]] = s[i];
				temp.append(1,s[i]);
			}
			else
			{
				result = (temp.size() > result) ? temp.size() : result;
				string::iterator it;
				for (it = temp.begin(); *it != s[i]; )
				{
					discover.erase(*it);
					it = temp.erase(it);
				}
				it = temp.erase(it);
				temp.append(1, s[i]);
			}
		}
		result = (temp.size() > result) ? temp.size() : result;
		return result;
	}
};
int main()
{
	Solution s;
	int i = s.lengthOfLongestSubstring();
	return 0;
}