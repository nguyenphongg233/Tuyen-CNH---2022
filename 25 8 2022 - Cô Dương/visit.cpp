#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 1e5 + 5;
const long long INF = 1e17;

#define ii pair<int,int>
#define X first
#define Y second

int n,m,k;
vector<ii> adj[MAX];
ii h[MAX];
int p[MAX];
priority_queue<ii,vector<ii>,greater<ii>> q;
struct query{
	int u,v,c;
	
	bool operator< (const query &a){
		return c < a.c;
	}
};

query qr[MAX];
int par[MAX];
int res = 0;
int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}

vector<query> kru;

signed main(){
	cin>>n>>m;
	
	for(int i = 1;i <= n;i++)h[i] = {INF,0},par[i] = i;
	for(int i = 1,u,v,c;i <= m;i++){
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
		qr[i] = {u,v,c};
	}
	
	cin>>k;
	for(int i = 1;i <= k;i++){
		cin>>p[i];
		h[p[i]] = {0,p[i]};
		q.push({0,p[i]});
	}
	
	while(!q.empty()){
		
		
		int dist = q.top().X;
		int u = q.top().Y;
		q.pop();
		
		//cout<<dist<<"\n";
		
		for(auto e : adj[u]){
			int v = e.X;
			int w = e.Y;
			
			if(h[v].X > dist + w){
				h[v] = {dist + w,h[u].Y};
				q.push({h[v].X,v});
			}
		}
		
	}
	
	
	for(int i = 1;i <= m;i++){
		int u = qr[i].u;
		int v = qr[i].v;
		int c = qr[i].c;
		
		int x = h[u].Y;
		int y = h[v].Y;
		
		if(x != y)
		kru.push_back({x,y,c + h[u].X + h[v].X});
		
	}
	
	res = h[1].X;
	
	sort(kru.begin(),kru.end());
	
	for(auto e : kru){
		
		int u = e.u;
		int v = e.v;
		int w = e.c;
		
		int x = find(u);
		int y = find(v);
		
		if(x == y)continue;
		
		res += w;
		par[x] = par[y];
		
	}
	
	
	cout<<res;
	
}