class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		unordered_map<ListNode*, bool> m;
		ListNode *x = head;
		while (x)
		{
			if (m.find(x) != m.end()) return true;
			m[x] = true;
			x = x->next;
		}
		return false;
	}
};