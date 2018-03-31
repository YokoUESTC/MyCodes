#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool bracketMatch(string &s)
{
	//bool flag=true;
	if (s.size() == 0 || s.size()%2 != 0)
		return false;
	stack<char> ch;
	for (int i = 0; i < s.size(); i++) 
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
		{
			ch.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') 
		{
			char top = ch.top();
			if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{'))
			{
				ch.pop();
			}
			else 
			{
				return false;
			}
		}
	}
    if (!ch.empty())
	   return false;
	return true;
}
int main()
{
	string str;
	getline(cin,str);
	if (bracketMatch(str))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}

