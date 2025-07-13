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

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int remaining = x - a[i];
        if(remaining < 0) continue;
        if (mpp.find(remaining) != mpp.end())
        {
            auto it = mpp.find(remaining);

            cout << it->second <<" "<<i + 1 << endl;
            return;
        }
        mpp[a[i]] = i+1;
    }

    cout << "IMPOSSIBLE" << endl;
}

signed main()
{
    fastio 
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}