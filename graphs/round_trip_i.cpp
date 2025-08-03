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

bool dfs(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &par)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (it != par[it])
        {

            if (vis[it])
            {

                cyclenode = it;
                par[cyclenode] = node;
                return 1;
            }

            else if (!vis[it])
            {
                par[it] = node;
                if (dfs(it, adj, vis, par))
                {
                    return 1;

                }
            }
        }
    }
}   

    void solve()
    {
        // your code goes here

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    signed main()
    {
        fastio int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
        return 0;
    }