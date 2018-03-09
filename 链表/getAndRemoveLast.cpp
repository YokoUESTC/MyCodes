//仅用递归函数和栈操作逆序一个栈
#include <iostream>
#include <stack>
using namespace std;
int getAndRemove(stack<int>& s)
{
	int result = s.top();
	s.pop();
	if (s.empty())
		return result;
	else
	{
		int last = getAndRemove(s);
	    s.push(result);
		return last;
	}
}
void reverse(stack<int>& s)
{
	if (s.empty())
		return;
	int i = getAndRemove(s);
	reverse(s);
	s.push(i);
}
void show(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
int main()
{
	stack <int>stk;
	//入栈
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout << "before:";
	show(stk);
	reverse(stk);
	cout << "after:";
	show(stk);
	system("pause");
	return 0;
}