#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v)
{
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = v.size() - 1; j >= i; j--)
		{
			if (v[j-1] > v[j])
				swap(v[j-1],v[j]);
		}
	}
}
int main()
{
	vector<int> input;
	vector<int> res;
	int n;
	do 
	{
		cin >> n;
		input.push_back(n);
	} while (cin.get()!='\n');
	bubbleSort(input);
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i] << " ";
	}
	system("pause");
	return 0;
}