#include<bits/stdc++.h>

using namespace std;
const long long MAX = 3e5 + 5;
#define int long long 

int up[MAX][21];
int h[MAX];
vector<pair<int,int>> adj[MAX];
int n;
int dp[MAX];

void dfs(int u,int p){
	for(auto e : adj[u]){
		
		int v = e.first;
		int c = e.second;
		
		if(v == p)continue;
		
		h[v] = h[u] + 1;
		up[v][0] = u;
		dp[v] = dp[u] + c;
		
		for(int i = 1;i < 20;i++){
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		
		dfs(v,u);
	}
}

int lca(int u,int v){
	
	if(h[u] != h[v]){
		if(h[u] < h[v])swap(u,v);
		
		int k = h[u] - h[v];
		
		for(int i = 0;(1 << i) <= k;i++){
			if(k >> i & 1)u = up[u][i];
		}
		
	}
	
	if(u == v)return u;
	
	int k = log2(h[u]);
	
	for(int i = k;i >= 0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
	
}

int getdist(int u,int v){
	return dp[u] + dp[v] - 2 * dp[lca(u,v)];
}

signed main(){
	
	if(ifstream("distance.inp")){
		freopen("distance.inp","r",stdin);
		freopen("distance.out","w",stdout);
	}
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ahanhxautraivcl;
	
	cin>>ahanhxautraivcl;
	
	cin>>n;
	
	for(int i = 1,u,v,c;i < n;i++){
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	
	dfs(1,0);
	
	int q;
	cin>>q;
	
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<getdist(u,v)<<"\n";
	}
}