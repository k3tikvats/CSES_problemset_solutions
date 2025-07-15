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

	int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0;
    int cnt=0;

    while(i<n&&j<m){
        if(b[j]>=a[i]-k&&b[j]<=a[i]+k){
            cnt++;
            i++;
            j++;
        }
        else if(b[j]<a[i]-k){
            j++;
        }
        else{
            i++;
        }
    }

    cout<<cnt<<endl;
        
	
}

signed main() {
    fastio
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}