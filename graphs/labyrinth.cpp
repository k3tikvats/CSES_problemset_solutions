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

vector<int>dijkstra(int n,vector<vector<pair<int,int>>>&adj,int src){
    set<pair<int,int>>st;
    vector<int>dist(n+1,LLONG_MAX);
    st.insert({0,src});
    dist[src]=0;

    while(!st.empty()){
        auto it=*(st.begin());

        int dis=it.first;
        int node=it.second;
        st.erase(it);
        for(auto jt:adj[node]){
            int adjNode=jt.first;
            int edgWt=jt.second;

            if(dis+edgWt<dist[adjNode]){
                if(dist[adjNode]!=LLONG_MAX){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=dis+edgWt;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
} 
 
void solve(){
    // your code goes here

	int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
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