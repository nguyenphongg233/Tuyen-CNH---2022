#include<bits/stdc++.h>

using namespace std;

const long long N = 55;
const long long INF = 1e9;

#define X first
#define Y second

int step[N][(1 << 13)][13];
int n,m;
vector<pair<int,int>>adj[N];
bool ok = 0;

struct wask{
	int u;
	int mask;
	int modd;
};

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		
		cin>>n>>m;
		for(int i = 1;i <= n;i++)adj[i].clear();
		ok = 0;
		for(int i = 1,u,v,c;i <= m;i++){
			cin>>u>>v>>c;
			adj[u].push_back({v,c});
			adj[v].push_back({u,c});
			
		}
		
		string s;
		cin>>s;
		if(s[0] == 'T')ok = 1;
		
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < (1 << 13);j++){
				for(int z = 0;z < 13;z++)
				    step[i][j][z] = INF;
			}
		}
		
		step[1][0][0] = 0;
		
		deque<wask> h;
		h.push_back({1,0,0});
		
		bool kk = 0;
		while(!h.empty()){
			
			int u = h.front().u;
			int mask = h.front().mask;
			int modd = h.front().modd;
			
			h.pop_front();
			
			if(u == n){
			  cout<<step[u][mask][modd]<<"\n";
			  kk = 1;
			  break;
			}
			for(auto e : adj[u]){
				
				int nxt_modd = (modd + e.Y) % 13;
				
				if((mask >> nxt_modd & 1 ) && ok)continue;
				if(nxt_modd == 0 && ok)continue;
				int nxt_mask = mask ^ (1 << nxt_modd);
				
				int v = e.X;
				int w = e.Y;
				
				if(step[v][nxt_mask][nxt_modd] > step[u][mask][modd] + w){
					step[v][nxt_mask][nxt_modd] = step[u][mask][modd] + w;
					h.push_back({v,nxt_mask,nxt_modd});
				}

			}
		}
		
		bool oki = 0;
		if(kk)continue;
		int res = INF;
		for(int i = 0;i < (1 << 13);i++){
			for(int z = 0;z < 13;z++){
				res = min(res,step[n][i][z]);
			}
		}
		
		cout<<(res == INF ? -1 : res)<<"\n";
		
	}
}