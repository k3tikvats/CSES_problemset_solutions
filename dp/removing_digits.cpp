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

int helper(int x, vector<int>& dp) {
    if(x==0)return 0;
   
    if(dp[x]!=-1)return dp[x];
  
    string s = to_string(x);
    int mini= INT_MAX;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')continue; // skip if digit is 0
        mini = min(mini, 1+helper(x-s[i]+'0',dp));
    }

    return dp[x]=mini;
}
 
void solve(){
    // your code goes here

	int n;
    cin>>n;

    vector<int>dp(n+1,-1);

    int ans=helper(n,dp);
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