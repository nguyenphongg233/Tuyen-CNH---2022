#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e3 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n,m,k;

int lab[MAX][MAX];
ii par[MAX][MAX];

ii find(int x,int y){
	
	if(par[x][y].X == x && par[x][y].Y == y)return {x,y};
	return par[x][y] = find(par[x][y].X,par[x][y].Y);
	
}

struct sdf{
	char w;
	int x,y;
};

int dx[] = {0,1};
int dy[] = {1,0};

bool outof(int x,int y){
	
	return (x < 1 || y < 1 || x > n || y > m);
	
}

vector<sdf> res;
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("CONNECTION.INP")){
		freopen("CONNECTION.INP","r",stdin);
		freopen("CONNECTION.OUT","w",stdout);
	}
	
	cin>>n>>m>>k;
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			par[i][j] = {i,j};
		}
	}
	for(int i = 1,u,v;i <= k;i++){
		char x;
		cin>>x;
		cin>>u>>v;
		
		
		int id = 0;
		if(x == 'D')id = 1;
		
		int x_ = u + dx[id];
		int y_ = v + dy[id];
		
		if(outof(x_,y_))continue;
		
		ii rt = find(x_,y_);
		ii rt2 = find(u,v);
		
		if(rt == rt2)continue;
		
		if(lab[rt.X][rt.Y] < lab[rt2.X][rt2.Y])swap(rt,rt2),swap(x_,u),swap(y_,v);
		
		lab[rt.X][rt.Y] += lab[rt2.X][rt2.Y];
		par[rt2.X][rt2.Y] = rt;
		
		
	}
	
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			
			for(int z = 0;z < 2;z++){
				
				char uber = (z == 1 ? 'D' : 'R');
				int x_ = dx[z] + i;
				int y_ = dy[z] + j;
				
				if(outof(x_,y_))continue;
				
				ii rt = find(x_,y_);
				ii rt2 = find(i,j);
				
				//cout<<x_<<" "<<y_<<"\n";
				
				if(rt == rt2)continue;
				
				//cout<<x_<<" "<<y_<<"\n";
				if(lab[rt.X][rt.Y] < lab[rt2.X][rt2.Y])swap(rt,rt2);
				
				lab[rt.X][rt.Y] += lab[rt2.X][rt2.Y];
				par[rt2.X][rt2.Y] = rt;
				
				res.push_back({uber,i,j});
			}
			
		}
	}
	
	cout<<res.size()<<'\n';
	for(auto e : res)cout<<e.w<<" "<<e.x<<" "<<e.y<<"\n";
	
}