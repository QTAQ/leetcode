class Solution
{
public:
	int findDuplicate(vector<int>& nums) 
	{
		int fast = 0; int slow = 0;
		while (true)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		fast = 0;
		while (true)
		{
			fast = nums[fast];
			slow = nums[slow];
			if (fast == slow) break;
		}
		return slow;
	}
};