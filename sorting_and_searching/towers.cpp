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

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int>towers;
    towers.push_back(a[0]);
    int j=0;
    int mini=a[0];
    for(int i=1;i<n;i++){
        if(mini>a[i]){
            mini=a[i];
            continue;
        }
        else{
            for(int )
            towers.push_back(a[i]);
        }
    }

    

        
	
}

signed main() {
    fastio
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}