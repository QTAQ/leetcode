class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		vector<int> v;
		ListNode *x = head;
		while (x)
		{
			v.push_back(x->val);
			x = x->next;
		}
		sort(v.begin(), v.end());
		x = head;
		for (int i = 0; i < v.size(); ++i)
		{
			x->val = v[i];
			x = x->next;
		}
		return head;
	}
};