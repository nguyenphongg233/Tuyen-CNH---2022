#include<bits/stdc++.h>

using namespace std;
const long long MAX = 2e6 + 5;

int sub,n;

vector<int> adj[MAX];
int color[MAX];
int dp[MAX];
int dp2[MAX];
int can[MAX / 32 + 5];

pair<int,int> get(int i){
	
	return {i / 32,i % 32};
	
	
}

void dfs(int u,int p){
	bool ok = 0;
	bool ok2 = 0;
	if(adj[u].size() == 1 && u != 1){
		
		dp[u] = color[u];
		pair<int,int> rt = get(u);
		
		can[rt.first] |= (1 << rt.second);
		return;
		
	}
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		
		if(dp[v] != color[u]){
			ok = 1;
		}
		
		if(dp[v] == -1){
			ok2 = 1;
		}
		
	}
	
	
	if(ok2)dp[u] = -1;
	
	if(!ok)dp[u] = color[u];
	else dp[u] = -1;
	if(!ok2){
		
		pair<int,int> rt = get(u);
		
		can[rt.first] |= (1 << rt.second);
		
	
	}
	
	
}

void dfs2(int u,int p){
	
	bool ok = 0;
	int cnt = 0;
	
	//cout<<u<<" "<<dp2[u]<<"\n";
	for(auto v : adj[u]){
		//cout<<v<<" ";
		if(v == p)continue;
		if(dp[v] == -1){
			cnt++;
			//cout<<v<<" ";
		}else 
		
		if(dp[v] != color[u]){
			cnt++;
		   // cout<<v<<" ";
		}
	}
	//cout<<"\n";
	if(dp2[u] != color[u])cnt++;
	
	//cout<<cnt<<"\n";
	for(auto v : adj[u]){
		if(v == p)continue;
		
		if((dp[v] == -1 || dp[v] != color[u]) && cnt == 1)dp2[v] = color[u];
		else if(cnt >= 2)dp2[v] = -1;
		else if(cnt == 0)dp2[v] = color[u];
		
		dfs2(v,u);
		
	}
	
	
	
}
signed main(){
	
	if(ifstream("colorful.inp")){
		freopen("colorful.inp","r",stdin);
		freopen("colorful.out","w",stdout);
	}
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>sub>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1;i <= n;i++){
		cin>>color[i];
	}
	memset(dp2,-1,sizeof dp2);
	dp2[1] = color[1];
	dfs(1,0);
	dfs2(1,0);
	
	vector<int> res;
	for(int i = 1;i <= n;i++){
		
		pair<int,int> rt = get(i);
		
		if((can[rt.first] >> rt.second & 1)  && dp2[i] != -1)res.push_back(i);
		//cout<<i<<" ";
		//cout<<can[i]<<" "<<dp2[i]<<"\n";
	}
	
	if(res.size() == 0)return cout<<"NO",0;
	cout<<"YES\n";
	for(auto v : res)cout<<v<<" ";
	
}