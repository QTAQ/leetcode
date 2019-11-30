#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct node
{
	int val;
	node *pre;
	node *succ;
	node():val(-1),pre(nullptr),succ(nullptr){}
	node(int a,node *p=nullptr,node *s=nullptr):val(a),pre(p),succ(s){}
};
class mList
{
public:
	int capacity = 0;
	int size = 0;
	node *head = nullptr;
	node *tail = nullptr;
	mList() = default;
	mList(int n) :capacity(n), size(0)
	{
		head = new node; tail = new node;
		head->succ = tail;
		tail->pre = head;
	}
	int remove()
	{
		node *x = tail->pre;
		int res = x->val;
		x->pre->succ = tail;
		tail->pre = x->pre;
		--size;
		return res;
	}
	bool insert(node *x, int &rem)
	{
		if (size < capacity)
		{
			node *f = head->succ;
			x->succ = f;
			x->pre = head;

			head->succ = x;
			f->pre = x;
			++size;
			return false;
		}
		rem = remove();
		node *f = head->succ;
		x->succ = f;
		x->pre = head;

		head->succ = x;
		f->pre = x;
		++size;
		return true;
	}
	void swap(node *x)
	{
		if (x == head->succ) return;
		x->pre->succ = x->succ;
		x->succ->pre = x->pre;

		node *f = head->succ;
		x->succ = f;
		x->pre = head;

		head->succ = x;
		f->pre = x;
	}
	void clear()
	{
		node *x = tail->pre;
		while (x != head)
		{
			x->pre->succ = tail;
			tail->pre = x->pre;
			x->pre = nullptr;
			x->succ = nullptr;
			x = tail->pre;
		}
		size=0;
	}
	~mList()
	{
		clear();
		delete head;
		delete tail;
	}

private:

};
class LRUCache
{
private:
	unordered_map<int, int> dict;
	unordered_map<int, node*> idx;
	mList list;
public:
	LRUCache(int capacity) :list(capacity)
	{
	}
	int get(int key)
	{
		if (dict.find(key) != dict.end())
		{
			node *x = idx[key];
			list.swap(x);
			return dict[key];
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (dict.find(key) != dict.end())
		{
			dict[key] = value;
			node *n = idx[key];
			list.swap(n);
			return;
		}
		node *x = new node(key);
		dict[key] = value;
		idx[key] = x;
		int rem = -1;
		if (list.insert(x, rem))
		{
			node *n = idx[rem];
			idx.erase(rem);
			dict.erase(rem);
			delete n;
		}
	}
};
int main()
{
	LRUCache c(2);
	c.put(2, 1);
	c.put(1, 2);
	c.put(2, 3);
	c.put(4, 1);
	c.get(1);
	c.get(2);
	return 0;
}