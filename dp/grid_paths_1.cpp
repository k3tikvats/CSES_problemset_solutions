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

int helper(int i,int j, vector<vector<char>>& a, vector<vector<int>> &dp)
{
    
    if (i == 0&&j==0)
    {
        return 1;
    }
    if( i < 0 || j < 0 || a[i][j] == '*')
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int up=helper(i-1,j, a, dp);
    int left=helper(i,j-1, a, dp);

    return dp[i][j] = up+left;
}
void solvememo(){
    // your code goes here

	int n;
    cin>>n;

    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n,-1));


    cout<<helper(n-1,n-1, a, dp)<<endl;
    return;
        
	
}
void solve(){
    // your code goes here

	int n;
    cin>>n;

    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n,0));
    dp[0][0] = 1; // Starting point`
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == '*') {
                dp[i][j] = 0; // Blocked cell
            } else if(i == 0 && j == 0) {
                dp[i][j] = 1; // Starting point
            } else {
                if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % M; // From above
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % M; // From left
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;
    return;
        
	
}

signed main() {
    fastio
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}