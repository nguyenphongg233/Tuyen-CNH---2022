#include<bits/stdc++.h>

using namespace std;

const long long MAX = 505;
const long long INF = 1e18;
const long long N = 1e5 + 5;
#define int long long
struct query{
	int u,v,c,id;
};

#define X first
#define Y second

vector<query> q;
vector<query> rt;

int n,m;

set<pair<int,int>> adj[MAX];
set<pair<int,int>> g[MAX];
vector<int> ed[MAX];

int par[MAX];
bool ok[N];

bool cmp(query a,query b){
	return a.c < b.c;
}

int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}

int res[N];

bool lienthong(int u){
	
	bool dd[MAX];
	memset(dd,0,sizeof dd);
	dd[u] = 1;
	deque<int> h;
	h.push_back(u);
	
	while(!h.empty()){
		int u_ = h.front();
		//cout<<u_<<"\n";
		h.pop_front();
		
		for(auto v : g[u_]){
			
			if(!dd[v.Y]){
				dd[v.Y] = 1;
				h.push_back(v.Y);
			}
			
		}
	}
	
	for(int i = 1;i <= n;i++)if(!dd[i])return false;
	return true;
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	q.push_back({-1,-1,-1,-1});
	for(int i = 1,u,v,c;i <= m;i++){
		cin>>u>>v>>c;
		q.push_back({u,v,c,i});
		adj[u].insert({c,v});
		adj[v].insert({c,u});
		rt.push_back({u,v,c,i});
	}
	
	for(int i = 1;i <= n;i++)par[i] = i;
	
	sort(rt.begin(),rt.end(),cmp);
	int cnt = 0;
	
	for(int i = 1;i <= m;i++){
		
		int u = rt[i - 1].u;
		int v = rt[i - 1].v;
		int w = rt[i - 1].c;
		
		int x = find(u);
		int y = find(v);
		
		if(x == y)continue;
		
		par[x] = y;
		
		g[u].insert({w,v});
		g[v].insert({w,u});
		
		cnt += w;
		
	}
	
	
	//cout<<cnt<<"\n";
	
	res[m] = cnt;
	
	for(int i = m;i >= 1;i--){
		
		//cout<<cnt<<"\n";
		int u = q[i].u;
		int v = q[i].v;
		int c = q[i].c;
		
		adj[u].erase({c,v});
		adj[v].erase({c,u});
		g[u].erase({c,v});
		g[v].erase({c,u});
		
		if(lienthong(u)){
			//cout<<u<<"\n";
			res[i - 1] = cnt;
			continue;
		}
		
		//g[u].erase({c,v});
		//g[v].erase({c,u});
		
		cnt -= c;
		
		deque<int> h;
		h.push_back(u);
		
		int ans = INF;
		
		bool dd[MAX];
		memset(dd,0,sizeof dd);
		vector<int> rte;
		
		while(!h.empty()){
			
			int u = h.front();
		    dd[u] = 1;   
			h.pop_front();
			//cout<<u<<"\n";
			
			for(auto e : g[u]){
				
				if(!dd[e.Y]){
					dd[e.Y] = 1;
					h.push_back(e.Y);
				}
				
				
			}
		}
		
		for(int i = 1;i <= n;i++){
			if(dd[i])rte.push_back(i);
		}
		int u_ = -1,v_ = -1;
	   
		for(auto u : rte){
			
			//cout<<u<<":\n";
			for(auto e : adj[u]){
				
				int v = e.Y;
				
				if(dd[v])continue;
				//cout<<e.Y<<" ";
				if(e.X < ans){
					ans = e.X;
					u_ = u;
					v_ = v;
					//break;
				}
			}
			//cout<<"\n";
		}
		
		
		
		if(u_ == -1 || v_ == -1 || ans == INF)break;
		g[u_].insert({ans,v_});
		g[v_].insert({ans,u_});
		cnt += ans;
		res[i - 1] = cnt;
	}
	
	for(int i = 1;i <= m;i++){
		
		ed[q[i].u].push_back(q[i].v);
		ed[q[i].v].push_back(q[i].u);
		
		bool dd[MAX];
		memset(dd,0,sizeof dd);
		
		deque<int> h;
		h.push_back(q[i].u);
		
		while(!h.empty()){
			
			int u = h.front();
			h.pop_front();
			
			dd[u] = 1;
			
			for(auto v : ed[u]){
				if(!dd[v]){
					dd[v] = 1;
					h.push_back(v);
				}
			}
			
		}
		
		
		bool ok = 1;
		for(int j = 1;j <= n;j++){
			if(!dd[j]){
				ok = 0;
				break;
			}
		}
		
		if(ok)break;
		res[i] = 123456789;
		
	}
	
	for(int i = 1;i <= m;i++)cout<<res[i]<<'\n';

}