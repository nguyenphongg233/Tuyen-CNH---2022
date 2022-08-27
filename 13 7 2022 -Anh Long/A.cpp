/*
   Date : 13 7 2022
   Tobi Where are you ?

*/

#include<bits/stdc++.h>

#define ll long long
#define task ""

#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n;
vi adj[MAX];
ll dp[MAX];
ll res = 0;
void dfs(ll u,ll p){
	dp[u] = 0;
	vi node;
	for(auto v : adj[u]){
		if(v == p)continue;
		dfs(v,u);	
		node.push_back(dp[v]);
	}
	
	sort(node.rbegin(),node.rend());
	
	if(node.size() > 1)dp[u] = node[0] + 1,res = max(res,node[0] + node[1] + 2);
	else if(node.size() == 1)dp[u] = node[0] + 1,res = max(res,node[0] + 1);
	else dp[u] = 0;
	
	//cout<<u<<" "<<p<<" "<<dp[u]<<"\n";
}
signed main(){
	cin>>n;
	for(ll i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	
	cout<<res * 3;
	
}