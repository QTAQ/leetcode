class Solution
{
public:
	void moveZeroes(vector<int>& nums) 
	{
		int idx = -1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				if (idx == -1) idx = i;
				else continue;
			}
			else
			{
				if(idx!=-1) swap(nums[i], nums[idx++]);
			}
		}
	}
	
};