class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int s = nums.size()-1;
		if (s <= 0) return true;
		int max = 0;
		for (int i = 0; i < s; ++i)
		{
            if(i>max) return false;
            int t = nums[i]+i;
            if(t>max) max = t;
			if (max >= s) return true;
		}
		return false;
	}
};
