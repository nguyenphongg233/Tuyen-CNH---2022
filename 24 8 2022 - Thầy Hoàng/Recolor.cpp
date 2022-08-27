#include<bits/stdc++.h>

using namespace std;
const long long MAX = 2e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n,m;
int color[MAX];
int par[MAX];
vector<int> adj[MAX];
int lab[MAX];

int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}

int res = 0;
void solve(){
	
	cin>>n>>m;
	res = 0;
	for(int i = 1;i <= n;i++){
		par[i] = i;
		cin>>color[i];
		adj[i].clear();
		lab[i] = 1;
	}
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(color[u] != color[v])continue;
		
		int x = find(u);
		int y = find(v);
		
		res = max({res,lab[x],lab[y]});
		if(x == y)continue;
		//cout<<"hi";
		if(lab[x] < lab[y])swap(x,y);
		
		lab[x] += lab[y];
		lab[y] = 0;
		par[y] = x;
		
		//cout<<x<<" "<<lab[x]<<"\n";
		res = max(res,lab[x]);
		//cout<<lab[x]<<" ";
		
	}
	
	//for(int i = 1;i <= n;i++)cout<<lab[i]<<" ";
	//cout<<"\n";
	//cout<<res<<"\n";
	for(int i = 1;i <= n;i++){
		
		map<int,int> mp;
		vector<ii> tmp;
		for(auto e : adj[i]){
			int v = find(e);
			//if(i == 6)cout<<e<<" "<<v<<" "<<lab[v]<<'\n';
			if(lab[v] <= 0)continue;
			mp[color[v]] += lab[v];
			
			tmp.push_back({v,lab[v]});
			
			lab[v] = 0;
			
			
		}
		
		for(auto e : mp){
			//if(i == 6)cout<<e.X<<" "<<e.Y<<"\n";
			if(color[i] != e.X)
			res = max(res,e.Y + 1);
			
		}
		
		for(auto e : tmp)lab[e.X] = e.Y;
		//for(int j = 1;j <= n;j++)cout<<lab[j]<<" ";
		//cout<<"\n";
	}
	
	cout<<res<<'\n';
	
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("RECOLOR.INP")){
		freopen("RECOLOR.INP","r",stdin);
		freopen("RECOLOR.OUT","w",stdout);
	}
	int t;
	cin>>t;
	
	while(t--){
		solve();
	}
	
}