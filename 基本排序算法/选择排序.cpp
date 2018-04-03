#include<iostream>
#include<vector>
using namespace std;

void selectSort(vector<int> &v)
{
	int min;
	for (int i = 0; i < v.size()-1; i++)
	{
		min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j])
				min = j;
		}
		if (i != min)
			swap(v[i],v[min]);
	}
}
int main()
{
	vector<int> r;
	int n;
	do {
		cin >> n;
		r.push_back(n);
	} while (cin.get()!='\n');
	selectSort(r);
	for (int i = 0; i < r.size(); i++)
		cout << r[i] << " ";
	system("pause");
	return 0;
}