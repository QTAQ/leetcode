#include<vector>

using namespace std;
class MinStack
{
public:
	vector<int> stk;
	vector<int> mstk;
	MinStack()
	{

	}

	void push(int x)
	{
		stk.push_back(x);
		if (mstk.empty() || x <= mstk.back())
		{
			mstk.push_back(x);
		}
	}

	void pop()
	{
		int t = stk.back();
		stk.pop_back();
		if (t == mstk.back()) mstk.pop_back();
	}

	int top()
	{
		return stk.back();
	}

	int getMin()
	{
		return mstk.back();
	}
};

int main()
{
	MinStack minStack;

	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);  
	minStack.getMin();   
	minStack.pop();
	minStack.top();
	minStack.getMin();
	return 0;
}


