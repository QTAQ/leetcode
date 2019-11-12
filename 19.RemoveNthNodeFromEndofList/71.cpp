#include<iostream>
#include<map>
using namespace std;
 struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *t = head;
		map<int, ListNode*> m;
		int i = 0;
		while (t)
		{
			m[i++] = t;

			t = t->next;
		}
		i = i - n;
		if (i == 0) return m[i + 1];
		m[i - 1]->next = m[i + 1];
		return m[0];
	}
};
int main()
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	ListNode * q= s.removeNthFromEnd(&a,2);
	return 0;
}