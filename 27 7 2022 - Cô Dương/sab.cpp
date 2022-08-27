

#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n,a[MAX],b[MAX];
int st[MAX << 2];
vector<int> ad[MAX];

void buildtree(int id, int l,int r){
	if(l == r){
		st[id] = a[l];
		return;
	}
	
	int m = l + r >> 1;
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	
	st[id] = min(st[id << 1],st[id << 1 | 1]);
	
}

int get(int id,int l,int r,int u,int v){
	
	if(u > r || v < l)return INF;
	if(u <= l && r <= v)return st[id];
	
	
	int m = l + r >> 1;
	
	return min(get(id << 1,l,m,u,v),get(id << 1 | 1,m + 1,r,u,v));
	
}

void update(int id,int l,int r,int x,int val){
	
	if(x < l || x > r)return;
	
	if(l == r){
		if(l == x){
			st[id] = val;
			
		}
		return;
	}
	
	int m = l + r >> 1;
	update(id << 1,l,m,x,val);
	update(id << 1 | 1,m + 1,r,x,val);
	
	st[id] = min(st[id << 1],st[id << 1 | 1]);
}

void solve(){
	
	cin>>n;
	
	
	for(int i = 1;i <= 4 * n;i++)st[i] = INF,ad[i].clear();
	
	for(int i = 1;i <= n;i++)cin>>a[i],ad[a[i]].push_back(i);
	for(int i = 1;i <= n;i++)cin>>b[i];
	
	//buildtree(1,1,n);
	
	bool ok = 1;
	
	for(int i = 1;i <= n;i++){
		if(ad[i].empty())continue;
		
		sort(ad[i].rbegin(),ad[i].rend());
		
		update(1,1,n,i,ad[i].back());
		
	}
	
	
	for(int i = 1;i <= n;i++){
		
		if(ad[b[i]].empty() || get(1,1,n,1,b[i]) < ad[b[i]].back()){
			ok = 0;
			break;
		}
		
		ad[b[i]].pop_back();
		
		update(1,1,n,b[i],(ad[b[i]].size() ? ad[b[i]].back() : INF));
	}
	cout<<((ok) ? "YES" : "NO")<<"\n";

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
}

signed main(){
	
	int t;
	cin>>t;
	
	while(t--){
		solve();
	}
	
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}