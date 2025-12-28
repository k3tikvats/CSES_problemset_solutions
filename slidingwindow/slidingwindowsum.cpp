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

void solve()
{
    // your code goes here

    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v;
    vector<int> winsum;
    int sum = x;
    v.push_back(x);
    for (int i = 1; i < n; i++)
    {
        if (i >= k)
        {
            winsum.push_back(sum);
            sum -= v[i - k];
        }
        x = (a * x + b) % c;
        v.push_back(x);
        sum += x;
    }
    winsum.push_back(sum);
    // for (int i = 0; i < winsum.size(); i++)
    // {
    //     cout << winsum[i] << " ";
    // }
    int ans = winsum[0];
    for(int i=1;i<winsum.size();i++){
        ans=ans ^ winsum[i];
    }
    cout << ans << "\n";
}

signed main()
{
    fastio

    solve();

    return 0;
}