#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getArrayMax(vector<int>& vec)
{
	int sum = 0;
	int res = INT_MIN;
	for (int i = 0; i < vec.size(); i++)
	{
		if (sum >= 0)
			sum += vec[i];
		else
			sum = vec[i];
		res = max(res,sum);
	}
	return res;
}

int maxSubRec(vector<vector<int>> &v, int n,int m)
{
	int maxVal=INT_MIN;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp(v[i]);
		maxVal = max(maxVal,getArrayMax(temp));
		for (int j = i+1; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				temp[k] += v[j][k];
			}
			maxVal = max(maxVal,getArrayMax(temp));
		}
	}
	return maxVal;
}
int main()
{
	vector<vector<int>> v = {
	{1,0,-1,1},
	{1,1,-1,1},
	{1,1,-1,0}
	};
	int res = maxSubRec(v,v.size(),v[0].size());
	cout << res;
	system("pause");
	return 0;
}
