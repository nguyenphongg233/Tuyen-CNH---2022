#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int sub,t;
int n;
vector<int> adj[MAX];
int color[MAX];
int par[MAX];
vector<int> g[MAX];
pair<int,int> graph[MAX];
int step[MAX];
int bac[MAX];

int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}
void join(int u,int v){
	int x = find(u);
	int y = find(v);
	
	if(x == y)return;
	
	if(x == 1){
		par[y] = x;
		bac[x] += bac[y];
		
	}else if(y == 1)par[x] = y,bac[y] += bac[x];
	else{
		
		if(bac[x] < bac[y])swap(x,y);
		
		par[y] = x;
		bac[x] += bac[y];
		
	}
	
}
void dfs(int u,int p){
	
	for(auto v : adj[u]){
		
		if(v == p)continue;
		
		if(color[v] == color[u]){
			join(v,u);
		}
		
		dfs(v,u);
		
	}
	
	
	
}

signed main(){
	
	if(ifstream("rbtree.inp")){
		freopen("rbtree.inp","r",stdin);
		freopen("rbtree.out","w",stdout);
	}
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>sub>>t;
	
	
	while(t--){
		
		cin>>n;
		

		
		for(int i = 1;i <= n;i++){
			adj[i].clear();
			g[i].clear();
			step[i] = 0;
			par[i] = i;
			bac[i] = 1;
		}
		
		for(int i = 1;i <= n;i++)cin>>color[i];
		for(int i = 1,u,v;i < n;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			graph[i] = {u,v};
		}
		
		dfs(1,0);
		
		for(int i = 1;i < n;i++){
			//cout<<graph[i].X<<" "<<graph[i].Y<<" "<<find(graph[i].X)<<" "<<find(graph[i].Y)<<"\n";
			g[find(graph[i].X)].push_back(find(graph[i].Y));
			g[find(graph[i].Y)].push_back(find(graph[i].X));
		}
		
		deque<int> h;
		
		h.push_back(1);
		step[1] = 1;
		int id = 0;
		int maxx = -1;
		while(!h.empty()){
			
			int u = h.front();
			//cout<<u<<" "<<step[u]<<"\n";
			h.pop_front();
			
			if(step[u] > maxx){
				maxx = step[u];
				id = u;
			}
			for(auto v : g[u]){
				//cout<<v<<" ";
				if(!step[v]){
					step[v] = step[u] + 1;
					h.push_back(v);
				}
			}
			//cout<<"\n";
			
		}
		
		//cout<<"\n";
		//cout<<maxx<<"\n";
		//for(int i = 1;i <= n;i++)cout<<step[i]<<'\n';
		for(int i = 1;i <= n;i++)step[i] = 0;
		//cout<<id<<"\n";
		h.push_back(id);
		step[id] = 1;
		while(!h.empty()){
			
			int u = h.front();
			h.pop_front();
			
			if(step[u] > maxx){
				maxx = step[u];
				id = u;
			}
			for(auto v : g[u]){
				if(!step[v]){
					step[v] = step[u] + 1;
					h.push_back(v);
				}
			}
			
		}
		
		//maxx--;
		
		//cout<<maxx<<"\n";
		cout<<(maxx % 2 == 0 ? maxx / 2 : (maxx - 1) / 2)<<' ';
		
		
		
		
	}
	
	

	
}