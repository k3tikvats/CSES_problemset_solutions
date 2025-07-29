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

vector<int>dijkstraa(int n,vector<vector<pair<int,int>>>&adj,int src){
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

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
    }


    vector<int>v=dijkstraa(n,adj,1);
    
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
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