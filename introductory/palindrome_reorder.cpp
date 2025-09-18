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

	string s;
    cin>>s;

    int n=s.size();

    vector<int>freq(26,0);
    for(int i=0;i<n;i++){
        freq[s[i]-'A']++;
    }
    int cntofodd=0;
    for(auto it:freq){
        if(n%2==0&&it%2!=0){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
        if(it%2==1)cntofodd++;
    }
    if(cntofodd!=1&&n%2==1){
        cout<<"NO SOLUTION"<<endl;
            return;
    }

    int j=0;
    int spclidx=0;
    string ans(n,'$');
    
    for(int i=0;i<26;i++){
        while(freq[i]!=0){
            if(freq[i]%2==1){
                spclidx=i;
                freq[i]--;
            }
            else{
                ans[j]=i+'A';
                ans[n-j-1]=i+'A';
                j++;
                freq[i]-=2;
            }
        }
        
    }
    if(n%2==1)ans[j]=spclidx+'A';

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