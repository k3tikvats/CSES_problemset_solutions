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

vector<int>dx={-1,0,1,0};//U,R,D,L
vector<int>dy={0,1,0,-1};
vector<char>drxn={'U','R','D','L'};
 
void solve(){
    // your code goes here

	int n,m;
    cin>>n>>m;

    vector<vector<char>> g(n, vector<char>(m));
    int sr=-1,sc=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                sr=i;
                sc=j;
            }
        }
    }
    queue<pair<int,int>> q;
    vector<vector<char>>visited(n,vector<char>(m,X));
    visited[sr][sc]='A';
    q.push({sr,sc});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first;
        int c=it.second;
        
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];

            if(nr>=0&&nr<n&&nc>=0&&nc<m&&visited!='X'&&g[nr][nc]!='#'){
                visited[r][c] = drxn[i];
                if(g[nr][nc]=='B'){
                    s+=drxn[i];
                    cout<<"YES"<<endl<<s.size()<<endl<<s<<endl;
                    return;
                }
                q.push({nr,nc});
            }

        }
        

    }
    
    cout<<"NO"<<endl;

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