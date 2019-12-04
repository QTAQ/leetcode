class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
        if (!head || !head->next) return true;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
        if (!fast) return (head->val == slow->val) ? true : false;
		ListNode *t = fast->next;
		fast->next = slow;
		slow->next = NULL;
		while (fast&&t)
		{
			slow = t->next;
			t->next = fast;
			fast = t;
			t = slow;
		}
		while (fast)
		{
			if (!head || fast->val == head->val)
			{
				fast = fast->next;
				head = head->next;
			}
			else return false;
		}
		return true;
	}
};