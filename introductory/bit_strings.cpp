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

    long long ans=1;

    for(int i=0;i<n;i++){
        ans=(ans*2)%M;
    }

    cout<<ans<<endl;

}

signed main() {
    fastio
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}