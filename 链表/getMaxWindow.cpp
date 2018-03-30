#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void getMaxWindow(vector<int> &v,int w)
{
	deque<int> qmax;
	vector<int> res;
	int index = 0;
	/*if (v.size() == 0 || w < 1 || v.size() < w)
		return ;*/
	for(int i=0;i<v.size();i++)
	{
		while (!qmax.empty() && v[qmax.front()] <= v[i])
			qmax.pop_back();
		qmax.push_back(i);
		//判断下标是否过期
		if (qmax.front() == i - w)
			qmax.pop_front();
		//装入res
		if (i >= w - 1)
		{
			res.push_back(v[qmax.front()]);
			index++;
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " " << endl;
	}
}
int main()
{
	vector<int> v;
	int n;
	int w;
	do {
		cin >> n;
		v.push_back(n);
	} while (cin.get() != '\n');
	cout << "w:";
	cin >> w;
	cout << endl;
      getMaxWindow(v,w);
	  //system("pause");
	return 0;
}