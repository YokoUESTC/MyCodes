#include<iostream>
#include<vector>
using namespace std;

void shellSort(vector<int> &v)
{
	int h=1;
	while (h < v.size())    h = 3 * h + 1;
	while (h>=1)
	{
		for (int i = h; i < v.size(); i++)
		{
			for (int j = i - h; j >= 0 && v[j + h]<v[j]; j-=h)
			{
				swap(v[j + h], v[j]);
			}
		}
		h = h / 3;
	}
	
}
int main()
{
	vector<int> res;
	int n;
	do {
		cin >> n;
		res.push_back(n);
	} while (cin.get() != '\n');
	shellSort(res);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("pause");
	return 0;
}