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
    cout<<n<<" ";

    while(n!=1){
        if(n%2==0){
        n = n / 2;
        }
        else{
        n = n * 3 + 1;
        }
        cout << n << " ";
    }
    

        
	
}

signed main() {
    fastio
	
	solve();
	
	return 0;
}