/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int i = l1->val + l2->val;
		int j = i / 10;
		int temp = 0;
		ListNode *result = new ListNode(i % 10);
		ListNode *tempNode = result;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL && l2 != NULL)
		{
			temp = l1->val + l2->val + j;
			j = temp / 10;
			temp = temp % 10;
			tempNode->next = new ListNode(temp);
			tempNode = tempNode->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 != NULL && tempNode != NULL)
		{
			tempNode->next = l1;
			do
			{
				if (!l1)
				{
					tempNode->next = new ListNode(1);
					return result;
				}
				temp = l1->val + j;
				j = temp / 10;
				temp = temp % 10;
				tempNode = l1;
				l1->val = temp;
				l1 = l1->next;
			} while (j == 1);
			return result;
		}
		else if (l2 != NULL && tempNode != NULL)
		{
			tempNode->next = l2;
			do
			{
				if (!l2)
				{
					tempNode->next = new ListNode(1);
					return result;
				}
				temp = l2->val + j;
				j = temp / 10;
				temp = temp % 10;
				tempNode = l2;
				l2->val = temp;
				l2 = l2->next;
			} while (j == 1);
			return result;
		}
		else if (tempNode != NULL)
		{
			if (j == 1)
			{
				tempNode->next = new ListNode(j);
			}
			return result;
		}
		return result;
	}
};