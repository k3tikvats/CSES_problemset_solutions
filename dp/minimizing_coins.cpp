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

int helper(int i, int x, vector<int> &c, vector<vector<int>> &dp)
{
	if (i < 0 || x < 0)
		return INT_MAX;
	if (x == 0)
	{
		return 0;
	}
	if (dp[i][x] != -1)
		return dp[i][x];
	int notpick = INT_MAX;
	if (i > 0)
		notpick = 0 + helper(i - 1, x, c, dp);

	int pick = INT_MAX;
	if (c[i] <= x)
		pick = 1 + helper(i, x - c[i], c, dp);

	return dp[i][x] = min(pick, notpick);
}
void solve_memo()
{
	// your code goes here

	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	// pick/not pick
	vector<vector<int>> dp(n, vector<int>(x + 1, -1));
	int result = helper(n - 1, x, c, dp);
	if (result == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << result << endl;
	}
}

void solve_tabulation()
{
	// your code goes here

	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	// pick/not pick
	vector<vector<int>> dp(n, vector<int>(x + 1, INT_MAX));
	for (int i = 0; i < n; i++)
		dp[i][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int val = 1; val <= x; val++)
		{
			int notpick = INT_MAX;
			if (i > 0)
				notpick = 0 + dp[i - 1][val];

			int pick = INT_MAX;
			if (c[i] <= val )
				pick = 1 + dp[i][val - c[i]];

			dp[i][val] = min(pick, notpick);
		}
	}
	if (dp[n - 1][x] == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dp[n - 1][x] << endl;
	}
}
void solve()
{
	// your code goes here

	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	// pick/not pick
	vector<int>prev(x+1, INT_MAX);
	prev[0]=0;
	for (int i = 0; i < n; i++)
	{
		vector<int>curr(x+1,INT_MAX);\
		curr[0]=0;
		for (int val = 1; val <= x; val++)
		{
			int notpick = INT_MAX;
			if (i > 0)
				notpick = 0 + prev[val];

			int pick = INT_MAX;
			if (c[i] <= val )
				pick = 1 + curr[val - c[i]];

			curr[val] = min(pick, notpick);
		}
		prev=curr;
	}
	if (prev[x] == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << prev[x] << endl;
	}
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