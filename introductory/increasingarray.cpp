#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fl(i, n) for(int i = 0; i < n; i++)
#define int long long
#define ll long long
#define in(n) long long n; cin >> n;
#define pb push_back
#define eb emplace_back
#define pp pop
unsigned long long M = 1000000007;

 
void solve(){
    // your code goes here

	int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(x[i]<x[i-1]){
            ans+=x[i-1]-x[i];
            x[i]=x[i-1];
        }
    }

    cout << ans << "\n";
}

signed main() {
    fastio
	
	solve();
	
	return 0;
}