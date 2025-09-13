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

int helper(vector<int>&a,vector<int>&b,int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return 1+helper(a,b,i-1,j-1,dp);
    }
    
    return dp[i][j]=max(helper(a,b,i-1,j,dp),helper(a,b,i,j-1,dp));
    

    
}
 
void solvememo(){
    // your code goes here

	int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<helper(a,b,n-1,m-1,dp)<<endl;
    return;


        
	
}
void solve(){
    // your code goes here

	int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;

    vector<int>ans;
    int i=n,j=m;
    int idx=dp[n][m]-1;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }

    for(int i=idx;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
        
	
}

signed main() {
    fastio
	int t=1;

	while(t--){
	    solve();
	}
	return 0;
}