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

int cyclenode = -1;
bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &par)
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (it != par[node])
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
    return 0;
}

void solve()
{
    // your code goes here

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    vector<int> vis(n + 1, 0);
    bool flag = dfs(1, adj, vis, par);
    vector<int> ans;

    if (flag)
    {

        int i = par[cyclenode];
        ans.push_back(par[cyclenode]);
        while (i != cyclenode)
        {
            ans.push_back(par[i]);
            i = par[i];
        }

        cout << ans.size();
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
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