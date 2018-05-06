#include<iostream>
#include<vector>
using namespace std;

int cutting(vector<int> &prices, int n, vector<int> &s) {
	// Write your code here
	
	vector<int> dp(n + 1, 0);
	
	//动态转换方程dp[i] = max{ dp[j] + dp[i - j] }
	for (int i = 1; i <= n; ++i)
	{
		int q = -1;
		for (int j = 1; j <= i; ++j)
		{
			if (q < prices[j - 1] + dp[i - j])
			{
				q = prices[j - 1] + dp[i - j];
				s[i] = j;
			}
		}
		dp[i] = q;
	}
	
	return dp[n];

}
int main()
{
	vector<int> p = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = p.size();
	vector<int> s(n+1, 0);
	int x = cutting(p, n, s);
	cout << x << endl;
	/*for (int k = 0; k < s.size();k++)
		cout << s[k];*/
	while (n > 0)
	{
		cout << s[n] << endl;
		n -= s[n];
	}
	system("pause");
	return 0;
}