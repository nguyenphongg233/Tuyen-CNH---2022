#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,m,k;
bool dd[MAX];
vi adj[MAX];
int dist[MAX];
bool ok[MAX];
int out[MAX];

void dfs(int u,int p){
	
	dist[u] = 0;
	ok[u] = dd[u];
	
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		if(ok[v])dist[u] = max(dist[u],dist[v] + 1),ok[u] = ok[v];
	}
	
	
	
	
}

void dfs2(int u,int p){
	
	
	int mx1 = -1,mx2 = -1;
	for(auto v : adj[u]){
		if(v == p)continue;
		
		if(!ok[v])continue;
		if(dist[v] == 0){
			
			if(dist[v] >= mx1){
			   mx2 = mx1;
			   mx1 = dist[v];
		    }else if(dist[v] > mx2)mx2 = dist[v];
		    
		    continue;
			
		}
		if(dist[v] + 1 >= mx1){
			mx2 = mx1;
			mx1 = dist[v] + 1;
		}else if(dist[v] + 1 > mx2)mx2 = dist[v] + 1;

	}
	
	//cout<<u<<" "<<mx1<<" "<<mx2<<"\n";
	
	for(auto v : adj[u]){
		if(v == p)continue;
		
		int longest = mx1;
		if(mx1 == dist[v] + 1 || (dist[v] == 0 && mx1 == dist[v]))longest = mx2;
		//cout<<u<<" ";
		//cout<<v<<" "<<out[u]<<" "<<longest<<"\n";
		
		out[v] = 1 + max(out[u],longest);
		dfs2(v,u);
	}
	
}
signed main(){
	
	cin>>n>>m>>k;
	
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	for(int i = 1,x;i <= m;i++){
		cin>>x;
		dd[x] = 1;
	}
	
	dfs(1,0);
	dfs2(1,0);
	
	
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(max(out[i],dist[i]) <= k)cnt++;
		
		//cout<<i<<" ";
		//cout<<dist[i]<<" "<<out[i]<<"\n";
	}
	cout<<cnt;
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}