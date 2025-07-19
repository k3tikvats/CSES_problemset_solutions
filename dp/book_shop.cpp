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

int helper(int i, int price, vector<int> &h, vector<int> &s, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (price >= h[i])
            return s[0];
        else
            return 0;
    }

    if (dp[i][price] != -1)
        return dp[i][price];

    int notTake = 0 + helper(i - 1, price, h, s, dp);
    int take = -1e9;

    if (price >= h[i])
        take = s[i] + helper(i - 1, price - h[i], h, s, dp);

    return dp[i][price] = max(take, notTake);
}
void solvememo()
{
    // your code goes here

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    cout << helper(n - 1, x, h, s, dp) << endl;
}
void solvetabulation()
{
    // your code goes here

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int p = 0; p <= x; p++)
    {
        if (p >= h[0])
            dp[0][p] = s[0];
        else
            dp[0][p] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int p = 0; p <= x; p++)
        {
            int notTake = dp[i - 1][p];
            int take = -1;

            if (p >= h[i])
                take = s[i] + dp[i - 1][p - h[i]];

            dp[i][p] = max(take, notTake);
        }
    }
    cout << dp[n - 1][x] << endl;
}
void solve()
{
    // your code goes here

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    // vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    vector<int> prev(x + 1, 0);

    for (int p = h[0]; p <= x; p++)
    {
        prev[p] = s[0];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(x + 1, 0);
        for (int p = 0; p <= x; p++)
        {
            int notTake = prev[p];
            int take = -1;

            if (p >= h[i])
                take = s[i] + prev[p - h[i]];

            curr[p] = max(take, notTake);
        }
        prev = curr;
    }
    cout << prev[x] << endl;
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