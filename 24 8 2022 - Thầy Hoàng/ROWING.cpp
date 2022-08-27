#include<bits/stdc++.h>

using namespace std;
const long long MAX = 8e3 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n,h;
int lab[MAX];

ii a[MAX];
int par[MAX];
int find(int u){
	return (u == par[u] ? u : par[u] = find(par[u]));
}

struct tmp{
	
	int x,y;
	float h;
	
};


vector<tmp> rt;
bool cmp(tmp a,tmp b){
	return a.h < b.h;
}
float calc(int i,int j){
	float t =  sqrt((a[i].X - a[j].X) * (a[i].X - a[j].X) + (a[i].Y - a[j].Y) * (a[i].Y - a[j].Y));
	return t;
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("ROWING.INP")){
		freopen("ROWING.INP","r",stdin);
		freopen("ROWING.OUT","w",stdout);
	}
	
	cin>>n>>h;
	
	for(int i = 1,u,v;i <= n;i++){
		
		cin>>u>>v;
		a[i] = {u,v};
		par[i] = i;
		lab[i] = 1;
	}
	
	par[n + 1] = n + 1;
	par[n + 2] = n + 2;
	
	a[n + 1] = {0,0};
	a[n + 2] = {0,h};
	
	for(int i = 1;i <= n;i++){
		rt.push_back({i,n + 1,a[i].Y});
		rt.push_back({i,n + 2,h - a[i].Y});
		for(int j = i + 1;j <= n;j++){
			rt.push_back({i,j,calc(i,j)});
		}
	}
	
	sort(rt.begin(),rt.end(),cmp);
	
	
	for(auto e : rt){
		
		int i = e.x;
		int j = e.y;
		float dist = e.h;
		
		int x = find(i);
		int y = find(j);
		
		if(x == y)continue;
		
		if(lab[x] < lab[y])swap(x,y);
		
		lab[x] += lab[y];
		lab[y] = 0;
		
		par[y] = x;
		
		if(find(n + 1) == find(n + 2))return cout<<dist,0;
		
		
	}
	
	
}