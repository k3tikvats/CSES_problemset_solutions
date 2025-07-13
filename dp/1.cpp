#include <bits/stdc++.h>

using namespace std;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define fl(i, n) for (int i = 0; i < n; i++)
#define int long long
#define ll long long
#define in(n)    \
	long long n; \
	cin >> n;
#define pb push_back
#define eb emplace_back
#define pp pop
unsigned long long M = 1000000007;

int helper(int n, vector<int> &dp)
{
	if (n < 0)
		return 0;
	if (n == 0)
	{

		return 1;
	}

	if (dp[n] != -1)
		return dp[n];

	int cnt = 0;
	for (int i = 1; i <= 6; i++)
	{
		cnt = (cnt + helper(n - i, dp)) % M;
	}

	return dp[n] = cnt;
}

void solvememo()
{
	// your code goes here

	int n;
	cin >> n;

	int cnt = 0;
	vector<int> dp(n + 1, -1);

	cout << helper(n, dp) << endl;
	return;
}


signed main()
{
	fastio int t = 1;

	while (t--)
	{
		solve();
	}
	return 0;
}