#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1048576 + 5;
const long long INF = 1e9;
#define X first
#define Y second

int n,m,sub;
bool spec[MAX];
vector<int> adj[MAX];
int dp[MAX][2][2];
// dp(i,in/out,1/0);

// 0 : tong khoang cach
// 1 : khoang cach lon nhat 

int h[MAX];
bool ap[MAX];
bool ap2[MAX];

void dfs(int u,int p){
	
	ap[u] = spec[u];
	for(auto v : adj[u]){
		if(v == p)continue;
		
		h[v] = h[u] + 1;
		dfs(v,u);
		
	    
		ap[u] = max(ap[u],ap[v]);
		
		
		if(ap[v]){
			
			dp[u][0][0] += dp[v][0][0] + 2 * (h[v] - h[u]);
			dp[u][0][1] = max(dp[v][0][1] + 1,dp[u][0][1]);
		}
	}
	
}

pair<int,int> longenough[MAX];
void dfs2(int u,int p){
	
	int sum_dist = dp[u][0][0] + dp[u][1][0];
	int cnt = 0;
	int mx1 = -1,mx2 = -1;
	for(auto v : adj[u]){
		
		if(v == p)continue;
		
		if(ap[v])cnt++;
		
		if(mx1 <= dp[v][0][1]){
			
			mx2 = mx1;
			mx1 = dp[v][0][1];
			
			
		}else if(mx2 < dp[v][0][1]){
			mx2 = dp[v][0][1];
		}
		
	}
	
	if(ap2[u])cnt++;
	if(spec[u])cnt++;
	
	
	for(auto v : adj[u]){
		
		if(v == p)continue;
		if((cnt == 1 && ap[v]) || cnt < 1){
			dp[v][1][1] = 0;
		    dp[v][1][0] = 0;
		}else {
			if(ap[v]){
				dp[v][1][0] = sum_dist - dp[v][0][0];
			}
			else dp[v][1][0] = sum_dist - dp[v][0][0] + 2 * (h[v] - h[u]);
			
			
			int longest = mx1;
			
			if(mx1 == dp[v][0][1])longest = mx2;
			ap2[v] = 1;
			dp[v][1][1] = max({dp[u][1][1]  + 1,longest + 2,longenough[u].X + 1,longenough[u].Y + 1});
			//longenough[v].X = dp[v][1][1];
			
			vector<int> ar = {dp[u][1][1]  + 1,longest + 2,longenough[u].X + 1,longenough[u].Y + 1};
			sort(ar.begin(),ar.end());
			
			longenough[v].X = ar[3];
			longenough[v].Y = ar[2];
			
		}
		
		if(spec[u] || ap2[u])ap2[v] = 1;
		dfs2(v,u);
	}
	
}


signed main(){
	
	cin>>sub;
	cin>>n>>m;
	
	memset(longenough,-1,sizeof longenough);
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1,x;i <= m;i++){
		cin>>x;
		spec[x] = 1;
	}
	
	
	dfs(1,0);
	dfs2(1,0);
	
	int res = 0;
	int longest = INF;
	
	for(int v = 1;v <= n;v++){
		
		cout<<v<<" "<<dp[v][1][1]<<" "<<longenough[v].X<<"\n";
		if(longest > dp[v][1][0] + dp[v][0][0] - dp[v][0][1] - longenough[v].X){
			
			longest = dp[v][1][0] + dp[v][0][0] - dp[v][0][1] - longenough[v].X;
			res = v;
			
		}
	}
	
	cout<<res<<" "<<longest;
}

