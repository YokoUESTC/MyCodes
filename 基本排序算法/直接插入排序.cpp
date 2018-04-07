#include<iostream>
#include<vector>
using namespace std;

void insertSort(vector<int> &v)
{

	for (int i = 1; i < v.size(); i++)
	{
		for (int j=i-1 ; j >=0&&v[j+1]<v[j]; j--)
		{
			swap(v[j+1],v[j]);
		}
	}
}
int main()
{
	vector<int> res;
	int n;
	do {
		cin >> n;
		res.push_back(n);
	} while (cin.get()!='\n');
	insertSort(res);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("pause");
	return 0;
}
