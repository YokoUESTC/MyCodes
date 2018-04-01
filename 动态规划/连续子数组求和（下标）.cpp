#include<iostream>
using namespace std;
int maxArray(int a[],int n)
{
	int sum = 0;
	int maxSum = INT_MIN;
	int max_start=0;
	int cur_start=0;
	int end=0;
	for (int i=0;i<n;i++)
	{

		if (sum >= 0)
			sum += a[i];
		else
		{
			sum = a[i];
			cur_start = i;
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			max_start = cur_start;
			end = i;
		}
	}
	cout << "begin" << max_start << "," << "end" << end<<endl;
	return maxSum;
}
int main()
{
	int a[5] = { -3,1,3,-3,4 };
	int g = maxArray(a,5);
	cout << g << endl;
	system("pause");
	return 0;
}