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
    if (x == 0)
    {
        return 1;
    }

    if (dp[i][x] != -1)
        return dp[i][x];
    int nottake = 0;
    if (i > 0)
        nottake = helper(i - 1, x, c, dp);
    int take = 0;
    if (c[i] <= x)
        take = helper(i, x - c[i], c, dp);

    return dp[i][x] = (nottake + take) % M;
}
void solvememo()
{
    // your code goes here

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ways = helper(n - 1, x, c, dp) % M;

    cout << ways << "\n";
}
void solvetabulation()
{
    // your code goes here

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1; // Base case: one way to make sum 0
    }
    for (int j = 1; j <= x; j++)
    {
        if (j % c[0] == 0)
            dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {

            int nottake = dp[i - 1][j];
            int take = 0;
            if (c[i] <= j)
                take = dp[i][j - c[i]];

            dp[i][j] = (nottake + take) % M;
        }
    }
    cout << dp[n - 1][x] << "\n";
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

    vector<int>prev(x+1,0);

    prev[0]=1;
    for (int j = 1; j <= x; j++)
    {
        if (j % c[0] == 0)
            prev[j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int>curr(x+1,0);
        curr[0]=1;
        for (int j = 1; j <= x; j++)
        {
            
            int nottake = prev[j];
            int take = 0;
            if (c[i] <= j)
                take = curr[j - c[i]];

            curr[j] = (nottake + take) % M;
        }
        prev=curr;
    }
    cout << prev[x] << "\n";
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