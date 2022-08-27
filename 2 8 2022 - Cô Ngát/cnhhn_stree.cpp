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

struct edge{
	int u,v,id;
};

vector<edge> blue,red;
int n,m1,m2,k;


int par[MAX][2];

int find(int u,bool ok){
	if(u == par[u][ok])return u;
	return par[u][ok] = find(par[u][ok],ok);
}

bool dd[MAX];

signed main(){
	
	cin>>n>>m1>>m2>>k;
	
	for(int i = 1,u,v;i <= m1;i++){
		
		cin>>u>>v;
		blue.push_back({u,v,i});
		
		
	}
	
	for(int i = 1,u,v;i <= m2;i++){
		
		cin>>u>>v;
		red.push_back({u,v,i});
		
	}
	
	for(int i = 1;i <= n;i++)par[i][0] = par[i][1] = i;
	
	
	for(auto v : blue){
		
		int x = find(v.u,0);
		int y = find(v.v,0);
		
		if(x == y)continue;
		
		par[x][0] = y;
		
		
		
		
	}
	vector<int> mustblue,mustred;
	
	for(auto e : red){
		int u = e.u;
		int v = e.v;
		
		int x = find(v,0);
		int y = find(u,0);
		
		if(x == y)continue;
		
		par[x][1] = y;
		par[x][0] = y;
		
		mustred.push_back(e.id);

		
	}
	
	
	//cout<<mustred.size();
	
	int up = n - k - 1;
	
	for(auto e : red){
		
		if(mustred.size() == up)break;
		
		int x = find(e.v,1);
		int y = find(e.u,1);
		
		if(x == y)continue;
		
		par[x][1] = y;
		mustred.push_back(e.id);
		
	}
	
	
	for(auto e : blue){
		
		
		if(mustblue.size() == k)break;
		int u = e.u;
		int v = e.v;
		
		int x = find(v,1);
		int y = find(u,1);
		
		if(x == y)continue;
		
		par[x][1] = y;
		mustblue.push_back(e.id);
		
		
	}
	
	//sort(mustblue.begin(),mustblue.end());
	//sort(mustred.begin(),mustred.end());
	
	for(auto v : mustblue)cout<<v<<"\n";
	for(auto v : mustred)cout<<v<<"\n";
	
}