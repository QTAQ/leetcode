/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define parent(i) (ceil((i)/2.0)-1)
#define lchild(i) ((i)*2+1)
#define rchild(i) (((i)+1)*2)


class myheap
{
public:
	myheap(vector<ListNode*> &v)
	{
        size = v.size();
        max = new ListNode(INT32_MAX);
		vec = heapify(v);
	}
	vector<ListNode*> heapify(vector<ListNode*> &v)
	{
		for (int i = v.size()-1; i >= 0; --i)
		{
			if(!v[i]){
                v[i] = max;
                --size;
            }
            down(v, i);
		}
		return v;
	}
	void down(vector<ListNode*> &v , int i)
	{
		int vsize = v.size();
		int p = i;
		int r = rchild(i);
		int l = lchild(i);
		while (r < vsize || l < vsize)
		{
			int t = (r < vsize) ? ((v[l]->val < v[r]->val)?l:r) : l;
			if (v[p]->val < v[t]->val) return;
			ListNode *tnode = v[p];
			v[p] = v[t];
			v[t] = tnode;
			p = t;
			l = lchild(p);
			r = rchild(p);
		}
		return;
	}
	ListNode* pop()
	{
		ListNode *r = vec[0];
		if (vec[0]->next)
		{
			vec[0] = vec[0]->next;
			down(vec,0);
		}
		else
		{
			vec[0] = max;
			--size;
		}
		down(vec,0);
		return r;
	}
	vector<ListNode*> vec;
	int size;
    ListNode* max;
};
 
class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
        if(lists.empty()) return NULL;
		myheap h(lists);
        if(h.size<=0) return NULL;
		ListNode *r = new ListNode(h.pop()->val);
		ListNode *t = r;
		while (h.size>0)
		{
			t->next = h.pop();
			t = t->next;
		}
		return r;
	}
};