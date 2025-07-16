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
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
void bfs(vector<vector<char>> &a, vector<vector<int>> &vis, int r, int c)
{
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    int n = a.size();
    int m = a[0].size();

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int row = node.first;
        int col = node.second;
        for (int i = 0; i <4; i++)
        {
            
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == '.' && !vis[nr][nc])
                {
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                }
            
        }
    }
}
void solve()
{
    // your code goes here

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j]&& a[i][j] == '.')
            {
                bfs(a, vis, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    fastio int t=1;

    while (t--)
    {
        solve();
    }
    return 0;
}