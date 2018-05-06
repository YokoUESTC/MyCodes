#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cutRod(int v[],int n)
{
	int *r = new int[n+1];
	int *s = new int[n + 1];
	r[0] = 0;
	//动态转换方程dp[i] = max{ dp[j] + dp[i - j] }
	for (int i = 1; i <= n; i++)
	{
		int q = -1;
		for (int j = 1; j <= i; j++)
		{
			//dp[i] = max(dp[i], dp[j] + dp[i - j]);
			if (q < v[j]+r[i - j]) {			
				q= v[j] + r[i - j];
				s[i] = j;
			}			
		}
		r[i] = q;
	}
	
	int x = n;
	while (x > 0)
	{
		cout << s[x] << endl;;
		x = x - s[x];
	}
	//for (int k = 0; k < n + 1; k++)
	//	cout << s[k] << endl;
	return r[n];
}
int main()
{
	int v[] = { 0,1, 5, 8, 9, 10, 17, 17, 20 };
	int c=cutRod(v,8);
	cout << c;
	system("pause");
	return 0;
}