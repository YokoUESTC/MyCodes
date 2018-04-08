#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& v,int left,int mid,int right)
{
	vector<int> aux;
	int i = left;
	int j = mid + 1;
	while (i<=mid&&j<=right)
	{
		if (v[i] > v[j])		
			aux.push_back(v[j++]);		
		else		
			aux.push_back(v[i++]);		
	}
	while (i <= mid)	
		aux.push_back(v[i++]);	
	while (j <= right)
		aux.push_back(v[j++]);	
	for (int k = left; k <= right; k++)	
		v[k] = aux[k - left];
}
void mergeSort(vector<int> &v,int left,int right)
{
	if (v.size() == 0 || left >= right)
		return;
	int mid = left +(right-left)/ 2;
	mergeSort(v,left,mid);
	mergeSort(v,mid+1,right);
	merge(v,left,mid,right);
}

int main()
{
	vector<int> res;
	int n;
	do {
		cin >> n;
		res.push_back(n);
	} while (cin.get() != '\n');
	mergeSort(res,0,res.size()-1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("pause");
	return 0;
}