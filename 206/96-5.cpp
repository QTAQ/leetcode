class Solution
{
public:
	ListNode *res = nullptr;
	ListNode *re(ListNode* head)
	{
		if (!head || !head->next) return head;
		if (!head->next->next)
		{
			res = head->next;
			head->next->next = head;
			head->next = NULL;
			return head;
		}
		re(head->next)->next = head;
		head->next = NULL;
		return head;
	}
	ListNode* reverseList(ListNode* head)
	{
		res = head;
		re(head);
		return res;
	}
};