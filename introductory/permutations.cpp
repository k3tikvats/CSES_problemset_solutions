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
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n<4){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            cout<<i<<" ";
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<i<<" ";
        }
    }
    
    


        
	
}

signed main() {
    fastio
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}