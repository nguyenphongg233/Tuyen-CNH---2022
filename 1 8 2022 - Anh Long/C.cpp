#include<bits/stdc++.h>

#define ll long long
//#define int long long 

#define X first
#define Y second

const long long MAX = 4000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


struct ed{
	int u,v;
	ll c;
};


bool cmp(ed a,ed b){
	return a.c < b.c;
}
int n,m,q;
vector<ed> et;
int par[MAX];


int find(int u){
	if(u == par[u])return u;
	return par[u] = find(par[u]);
}

vector<pair<int,ll>> adj[MAX];
ll sum = 0;
ll dist[MAX][MAX];
bool dd[MAX][MAX];


signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)par[i] = i;
	for(int i = 1,u,v;i <= m;i++){
		ll c;
		cin>>u>>v>>c;
		et.push_back({u,v,c});
		
	}
	
	sort(et.begin(),et.end(),cmp);
	
	
	for(auto e : et){
		int u = e.u;
		int v = e.v;
		ll c = e.c;
		
		
		int x = find(u);
		int y = find(v);
		
		if(x == y)continue;
		
		par[x] = y;
		sum += c;
		
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
		
	}
	
	for(int i = 1;i <= n;i++){
		
		dist[i][i] = 0;
		dd[i][i] = 1;
		
		deque<int> h;
		
		h.push_back(i);
		//cout<<"#"<<i<<" :\n";
		while(!h.empty()){
			
			int u = h.front();
			h.pop_front();
			
			
			for(auto e : adj[u]){
				
				int v = e.X;
				ll c = e.Y;
				
				if(dd[i][v])continue;
				dd[i][v] = 1;
				dist[i][v] = max(dist[i][u],c); 
				h.push_back(v);
			}
		}
		
		//for(int j = 1;j <= n;j++)cout<<dist[i][j]<<" ";
		//cout<<"\n";
		
		
		
	}
	cin>>q;
	
	while(q--){
		
		int x,y;
		cin>>x>>y;
		
		cout<<sum - dist[x][y]<<"\n";
		//cout<<dist[x][y]<<"\n";
		
		
	}
	

	
}