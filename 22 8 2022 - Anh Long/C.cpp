#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int par[MAX];
int color[MAX];
int cnt[MAX];
vector<ii> adj[MAX];


int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}

int n,q;

void bfs(int id,bool c){
	
	deque<ii> h;
	
	h.push_back({id,c});
	map<int,bool> dd; 
	
	while(!h.empty()){
		
		int u = h.front().X;
		int ce = h.front().Y;
		
		color[u] = ce;
		dd[u] = 1;
		h.pop_front();
		
		for(auto e : adj[u]){
			
			int v = e.X;
			int w = e.Y;
			
			if(dd[v])continue;
			
			if(w == 2){
				
				h.push_back({v,1 - color[u]});
			}else{
				h.push_back({v,color[u]});
			}
		}
	}
	
}
signed main(){
	
	cin>>n>>q;
	
	
	for(int i = 1;i <= n;i++){
		par[i] = i;
		cnt[i] = 1; 
		color[i] = 0;
	}
	for(int i = 1,u,v;i <= q;i++){
		char s;
		cin>>s>>u>>v;
		
		if(s == 'Q'){
			
			int x = find(u);
			int y = find(v);
			
			if(x != y)cout<<"?\n";
			else{
				
				//cout<<u<<" "<<v<<" "<<color[u]<<" "<<color[v]<<"\n";
				//cout<<x<<" "<<y<<"\n";
				cout<<(color[u] != color[v] ? "A" : "R")<<'\n';
				
			}
			//continue;
			
		}else 
		
		if(s == 'A'){
			
			int x = find(u);
			int y = find(v);
			
			if(x == y)continue;
			if(cnt[x] < cnt[y])swap(x,y),swap(u,v);
			
			cnt[x] += cnt[y];
			par[y] = x;
			
			if(color[u] == color[v]){
				//cout<<y<<"\n";
				bfs(v,1 - color[u]);
				
				
			}
			
			
			
			adj[u].push_back({v,2});
			adj[v].push_back({u,2});
		}else if(s == 'R'){
			
			int x = find(u);
			int y = find(v);
			
			if(x == y)continue;
			if(cnt[x] < cnt[y])swap(x,y),swap(u,v);
			
			cnt[x] += cnt[y];
			par[y] = x;
			
			if(color[u] != color[v]){
				//cout<<y<<" "<<"\n";
				bfs(v,color[u]);
			}
			
			
			
			adj[u].push_back({v,1});
			adj[v].push_back({u,1});
			
			
		}
		
		//for(int i = 1;i <= n;i++)cout<<color[i]<<" ";
		//cout<<"\n";
		
	}
	
	
}
