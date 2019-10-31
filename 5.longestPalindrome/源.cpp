#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	string longestPalindrome()
	{
		string s = "aabbbcccbbbaaaabbbcccbbbaa";
		if (s.size() == 0 || s.size() == 1)
		{
			return s;
		}
		string result = {s[0]};
		int l = 0 , r = 0;
		bool f = false, t = false;
		for (int i = 1; i < s.size(); )
		{
			if (s[i - 1] == s[i])
			{
				l = i - 2;
				r = i + 1;
				while (r<s.size() && s[r]==s[i]) r++;
				t = true;
				f = true;
			}
			else if (i + 1 < s.size() && s[i - 1] == s[i + 1])
			{
				l = i - 2;
				r = i + 2;
				t = false;
				f = true;
			}
			i = (t) ? r : i + 1;
			while (f && l >= 0 && r < s.size())
			{
				if (s[l] == s[r])
				{
					l--; r++;
				}
				else 
				{
					break;
				}
			}
			if (f && (r - l - 1) > result.size())
			{
				string temp;
				for (int j = 0; j < r - l - 1; j++)
				{
					temp.append(1, s[j + l + 1]);
				}
				result = temp;
			}
			f = false;
			t = false;
		}
		return result;
	}
};
int main()
{
	Solution s;
	string a = s.longestPalindrome();
	string q = "aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
		;
	string w = "aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa"
		;
	return 0;
}